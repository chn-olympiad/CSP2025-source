#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 510
#define mod 998244353
int n,h,m,pre[N],c[N],sumc[N],f[2][N][N],g[N][N];
int fac[2*N],inv[2*N];
string s;
namespace AAA
{
	int n,m,a[N],c[N],p[N],ans;
	string s;
	void solve()
	{
		int pre=0,qwq=0;
		for(int i=1;i<=n;i++)
		{
			if(pre>=c[p[i]]||a[i]==0)
			{
				if(a[i]!=0)
				 qwq++;
				pre++;
			}
		}
		if(n-pre>=m)
		{
			ans=(ans+1)%mod;
		}
	}
	void man(int _n,int _m)
	{
		n=_n;
		m=_m;
		cin>>s;
		for(int i=1;i<=n;i++)
		if(s[i-1]=='1')
		 a[i]=1;
		for(int i=1;i<=n;i++)
		 cin>>c[i];
		for(int i=1;i<=n;i++)
		 p[i]=i;
		int tot=1;
		for(int i=1;i<=n;i++)
		 tot*=i;
		while(tot--)
		{
			solve();
			next_permutation(p+1,p+n+1);
		}
		cout<<ans<<endl;
	}
}
int ksm(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k&1)
		 res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		k>>=1;
	}
	return res;
}
int C(int n,int m)
{
	if(n<m)
	 return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int calc(int n,int m)
{
	return 1ll*C(n,m)*fac[m]%mod;
}
void add(int &x,int y)
{
	if((x+=y)>=mod)
	 x-=mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<2*N;i++)
	 fac[i]=1ll*fac[i-1]*i%mod;
	inv[2*N-1]=ksm(fac[2*N-1],mod-2);
	for(int i=2*N-1;i>=1;i--)
	 inv[i-1]=1ll*inv[i]*i%mod;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>h>>m;
	if(h<=10)
	{
		AAA::man(h,m);
		return 0;
	}
	cin>>s;
	s=" "+s;
	int tot=0;
	for(int i=1;i<=h;i++)
	if(s[i]=='1')
	{
		pre[++n]=tot;
	}
	else
	{
		tot++;
	}
	for(int i=1;i<=h;i++)
	{
		cin>>c[i];
		sumc[c[i]]++;
	}
	for(int i=1;i<=h;i++)
	 sumc[i]+=sumc[i-1];
	if(m>n)
	{
		cout<<0<<endl;
		return 0;
	}
	f[0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		memset(f[(i&1)^1],0,sizeof(f[(i&1)^1]));
		if(i>0)
		{
//			cerr<<"debug G "<<i<<endl;
//			for(int j=pre[i];j<=pre[i]+i;j++)
//			for(int x=0;x<=i;x++)
//			 cerr<<"pos "<<i<<" failed "<<j-pre[i]<<"("<<j<<")"<<" upon "<<x<<"::"<<g[j][x]<<endl;
			for(int j=pre[i];j<=pre[i]+(i-1);j++)
//			for(int j=0;j<=h;j++)
			{
				for(int x=0;x<=i;x++)
				if(g[j][x])
				{
					add(f[i&1][j][x+1],g[j][x]);
					int y=sumc[j]-((i-1)-x);
//					cerr<<j<<" "<<x<<"-->y="<<y<<" || "<<g[j][x]<<endl;
					int tmp=1ll*g[j][x]*y%mod;
					int cnt=sumc[j+1]-sumc[j];
					for(int k=0;k<=min(x,cnt);k++)
					 add(f[i&1][j+1][x-k],1ll*tmp*calc(cnt,k)%mod);
				}
			}
		}
//		cerr<<"debug F "<<i<<endl;
//		for(int j=pre[i];j<=pre[i]+i;j++)
//		for(int x=0;x<=i;x++)
//		 cerr<<"pos "<<i<<" failed "<<j-pre[i]<<"("<<j<<")"<<" upon "<<x<<"::"<<f[i&1][j][x]<<endl;
		if(i<n)
		{
			memset(g,0,sizeof(g));
			for(int j=pre[i];j<=pre[i]+i;j++)
//			for(int j=0;j<=h;j++)
			{
				for(int x=0;x<=i;x++)
				if(f[i&1][j][x])
				{
//					cerr<<"ind "<<j<<" "<<x<<"::"<<f[i&1][j][x]<<endl;
					int cnt=sumc[j+(pre[i+1]-pre[i])]-sumc[j];
//					cerr<<"??"<<cnt<<"||"<<j+(pre[i+1]-pre[i])<<" "<<j<<endl;
					for(int k=0;k<=min(x,cnt);k++)
					{
//						cerr<<"to "<<j+(pre[i+1]-pre[i])<<" "<<x-k<<" :: "<<f[i&1][j][x]<<"*"<<calc(cnt,k)<<endl;
						add(g[j+(pre[i+1]-pre[i])][x-k],1ll*f[i&1][j][x]*calc(cnt,k)%mod);
					}
				}
			}
		}
	}
	int ans=0;
//	cerr<<"L="<<pre[n]<<" R="<<pre[n]+(n-m)<<"||m="<<m<<endl;
	for(int j=pre[n];j<=pre[n]+(n-m);j++)
	{
		int t=sumc[h]-sumc[j];
		for(int x=0;x<=min(n,t);x++)
		{
//			cerr<<"pos "<<n<<" failed "<<j-pre[n]<<"("<<j<<")"<<" upon "<<x<<"::"<<f[n&1][j][x]<<endl;
			add(ans,1ll*f[n&1][j][x]*calc(t,x)%mod);
		}
	}
	cout<<1ll*ans*fac[h-n]%mod<<endl;
}
