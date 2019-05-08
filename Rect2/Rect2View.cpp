
// Rect2View.cpp : implementation of the CRect2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Rect2.h"
#endif

#include "Rect2Doc.h"
#include "Rect2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRect2View

IMPLEMENT_DYNCREATE(CRect2View, CView)

BEGIN_MESSAGE_MAP(CRect2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRect2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CRect2View construction/destruction

CRect2View::CRect2View() noexcept
{
	// TODO: add construction code here

}

CRect2View::~CRect2View()
{
}

BOOL CRect2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRect2View drawing

void CRect2View::OnDraw(CDC* /*pDC*/)
{
	CRect2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CRect2View printing


void CRect2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRect2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRect2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRect2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRect2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRect2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRect2View diagnostics

#ifdef _DEBUG
void CRect2View::AssertValid() const
{
	CView::AssertValid();
}

void CRect2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRect2Doc* CRect2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRect2Doc)));
	return (CRect2Doc*)m_pDocument;
}
#endif //_DEBUG


// CRect2View message handlers


void CRect2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	for (int x = 0; x < rect.Width(); x += 20)
	{
		dc.MoveTo(x, 0);
		dc.LineTo(x, rect.Height());
	}
	CView::OnRButtonDown(nFlags, point);
}


//void CRect2View::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CView::OnMButtonDown(nFlags, point);
//}


void CRect2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 255));
	dc.SelectObject(&pen);
	for (int x = 0; x < rect.Height(); x += 20)
	{
		dc.MoveTo(0, x);
		dc.LineTo(rect.Width(), x);
	}
	CView::OnLButtonDown(nFlags, point);
}
