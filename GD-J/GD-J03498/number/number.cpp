#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if('0'<=s[i]&&s[i]<='9') {
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++) {
		cout<<v[i];
	}
	return 0;
}
/*
现在距离考试结束还有2h30min11s，既然都要爆零了，那么是时候写迷惑行为大赏了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
luogu id:114****
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
