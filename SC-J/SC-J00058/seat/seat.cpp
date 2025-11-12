#include<bits/stdc++.h>
using namespace std;
//define int long long
char ibuf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++) 
#define per(i,r,l) for(int i=r;i>=l;i--)
#define endl '\n'
inline void read(int &x)
{
	x=0;int f=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x*=f;
}

//
const int N=112;
int n,m,a[N];
signed main()
{
//	cin.tie(0)->sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n*m)cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int k=1;
	rep(i,1,n*m)if(a[i]==tmp)k=i;
	int t=(k-1)/n+1;
	int x=k-n*(t-1);
	if(t&1)cout<<t<<' '<<x;
	else cout<<t<<' '<<n-x+1;
	return 0;
}