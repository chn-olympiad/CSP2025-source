#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;int f=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x*=f; 
}

//
const int N=2e3+12,L=2e3+12,d=131,dd=137;
int n,q,hs[N][2][L],hq[2][L],ans;
char s[N][2][L],t[2][L];
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
signed main()
{
//	cin.tie(0)->sync_with_stdio(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	__lg(4);__builtin_popcount(4);
	 
	cin>>n>>q;
	rep(i,1,n)
	{
		rep(j,0,1)
		{
			cin>>(s[i][j]+1);
			int l=strlen(s[i][j]+1);
			rep(k,1,l)
			{
				hs[i][j][k]=hs[i][j][k-1]*d+s[i][j][k];
			 } 
		}
	}
	
	while(q--)
	{
		ans=0;
		int lq;
		rep(j,0,1)
		{
			cin>>(t[j]+1);
			int lq=strlen(t[j]+1);
			rep(k,1,lq)
			{
				hq[j][k]=hq[j][k-1]*d+t[j][k];
			 } 
		}
		int to=hq[1][lq];
		rep(i,1,n)
		{
			int le=strlen(s[i][0]+1);
			rep(j,le,lq)
			{
				int o=hs[i][0][le];
				int a=hq[0][j-le],b=hq[0][j]-a*qpow(d,le),c=hq[0][lq]-hq[o][j]*qpow(d,lq-j);
				if(b!=o)continue;
				int ch=a*qpow(b,le)+o;
				ch=ch*qpow(b,lq-j)+c;
				if(ch==to)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}