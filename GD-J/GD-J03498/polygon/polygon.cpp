#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,l[5003],ansxxxx;
bool IsMaxLI1=1;
map<vector<int>,bool>vis;
void check(int cur,int cnt,int sum,int need,vector<int>c) {
//	cout<<ansxxxx<<"\n";
	if(l[cur]==0) return;//why?
	if(cnt==need||cur>n) {
		if(sum>l[cur]*2&&vis[c]==0) {
			vis[c]=1;
//			for(int i=0;i<c.size();i++) {
//				cout<<c[i]<<" ";
//			}
//			printf("\t\t\tlastchoice=%d\t\tsum=%d\t\tl_max*2=%d\n",l[cur],sum,l[cur]*2);
			ansxxxx++;
			return;
		}
	}
	for(int i=cur+1;i+need-cnt-1<=n;i++) {
		check(i,cnt,sum,need,c);//不选 
		c.push_back(i);
		check(i,cnt+1,sum+l[i],need,c);//选 
		c.pop_back();
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++) {
		cin>>l[i];
		maxn=max(maxn,l[i]);
		if(l[i]>1) IsMaxLI1=0;
	}
	sort(l+1,l+n+1);
	if(n<=3) {//1~3:12pts
		if(l[1]+l[2]+l[3]>2*maxn) cout<<1;
		else cout<<0;
	}
	else if(IsMaxLI1) {//15~20:20pts
		//cout<<C_n^{(3,n)}
		long long ans=0,nf=1,mf=1;
		for(int i=1;i<=n;i++) {
			nf=(nf*i)%MOD;
		}
		for(int i=3;i<=n;i++) {
			mf=1;
			for(int j=1;j<=i;j++) mf=(mf*j)%MOD;
			for(int j=1;j<=n-i;j++) mf=(mf*j)%MOD;
			ans+=nf/mf;
		}
		cout<<ans%MOD;
	}
	else {//4~6:0pts
		for(int i=3;i<=n;i++) {
			vector<int>c;
			check(1,0,0,i,c);
			c.push_back(1);
			check(1,1,l[1],i,c);
			c.pop_back();
		}
		cout<<ansxxxx;
	}
	return 0;
}
/*
这题要用DP吗 
现在距离考试结束还有2h30min11s，既然都要爆零了，那么是时候写迷惑行为大赏了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
luogu id:***5044
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
	O2
	C++
	PAS
	PY
	C++11
	C++14
	C++17
	cpp
	oiliveforever
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
	
	I Love OI Forever
	  -------
	 /       \
	|(.)  (.)|
	| ||  || |
	\   ^   /
	 -------
	 
	完了完了完了 ……...... 
	
	Why the password to decode the .zip file is "#上4善3若6水4"(the first charecter of every word is 大写)? 
*/
