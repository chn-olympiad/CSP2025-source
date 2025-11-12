#include<bits/stdc++.h>
using namespace std;
int n,m,a[1003],r,pr,M[15][15];//M[列][行]
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==r) pr=i;
	}
	int cnt=0;
	for(int i=1;i<=m;i++) {//列 
		if(i%2==1) {//奇数列
			for(int j=1;j<=n;j++) {//行 
				cnt++;
				M[i][j]=cnt;
				if(cnt==pr) {
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		else {//偶数列
			for(int j=n;j>=1;j--) {//行 
				cnt++;
				M[i][j]=cnt;
				if(cnt==pr) {
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
	}
//	cout<<"\n";
//	for(int i=1;i<=m;i++) {
//		for(int j=1;j<=n;j++) {
//			cout<<M[j][i]<<" ";
//		}
//		cout<<"\n";
//	}
	system("start seat.out");
	return 0;
}
/*
现在距离考试结束还有2h30min11s，既然都要爆零了，那么是时候写迷惑行为大赏了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
luogu id:*145***
keywords:
	pts
	ccf
	CCF
	cff
	CFF
	fcc
	FCC
	ffc
	FFC
	KFC
	MDL
	luogu
	lg
	kkksc03
	小粉兔 
	feropen
	D:/
	D:\
	fre open
	fer open
	AK
	IOI
	CSP
	J
	S
	AC
	WA
	TLE
	MLE
	OLE
	UKE
	CYB
	CYB Sxxxx
	Jimmy Sxxxx
	Bowen Sxxxx
	AFO
	OI
	OJ
	迷惑行为大赏
	GD
	广东
	SZ
	深圳
	orz
	%
	q
	w
	e
	r
	t
	y
	u
	i
	o
	p
	a
	s
	d
	f
	g
	h
	j
	k
	l
	z
	x
	c
	v
	b
	n
	m
	1
	2
	3
	4
	5
	6
	7
	8
	9
	0
	!
	@
	#
	$
	%
	^
	&
	*
	(
	)
	_
	+
	-
	=
	numbar
	saet
	xro
	palygon
	polygan
	palygan
	qolygon
	114514
	1919810
	CSP AK ME!
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	freopen("polygon.in","w",stdin);
	freopen("polygon.in","r",stdout);
	freopen("polygon.in","w",stdout);
	freopen("polygon.out","r",stdout);
	freopen("polygon.out","w",stdin);
	freopen("polygon.out","r",stdin);
	fclose(in);
	fclose(out);
*/
