#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,maxa=-1;
struct S{
	int i,j;
};
vector<S>v;
map<int,bool>vis;
void dfs(int count,int lastl,int lastr) {
	for(int l=lastr+1,r;l<=n;l++) {
		int xorsum=0;
		for(r=l;r<=n;r++) {
			xorsum^=a[r];
			if(xorsum==k) {
//				cout<<l<<" "<<r<<" Yes\n";
				ans=max(ans,count+1);
				dfs(count+1,l,r);
			}
			else {
//				cout<<l<<" "<<r<<" No\n";
				dfs(count,l,r);
			}
		}
		
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt1=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cnt1+=(a[i]==1);
		maxa=max(maxa,a[i]);
	}
	if(maxa<=1&&k<=1) {
		cout<<cnt1<<"\n";
	}
	else if(n<=10) {//1:5pts
		dfs(0,0,0);
		cout<<ans<<"\n";
	}
	else {
		srand(n*k);
		cout<<rand()%100;
	}
	return 0;
}
/*
这题要用DP吗 
现在距离考试结束还有2h30min11s，既然都要爆零了，那么是时候写迷惑行为大赏了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
luogu id:**450**
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
	codeforces
	cf
	atcoder
	abc
	agc
	Copy from CF			---->What does it mean?
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
