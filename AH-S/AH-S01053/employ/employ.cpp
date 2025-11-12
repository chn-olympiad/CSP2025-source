#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define popcount(x) __builtin_popcount(x)
constexpr int N=505;
constexpr ll mod=998244353;
char s[N];
ll f[2][N][N],dp[2][N],g[(1<<18)+5][19],ans,fac[N],inv[N];
int c[N],t[N],cnt[2],n,m;
void solve()
{
/*	f[0][0][0]=1;
	int cur=1,cnt=0;
	for(int i=1;i<=n;cur^=1,++i)
	{
		memset(f[cur],0,sizeof f[cur]);
		for(int j=0;j<i;++j)
			for(int k=0;k<i;++k)
			{
				if(c[i])
					f[cur][j][k+1]+=f[!cur][j][k];
				if(j+1>c[i])
					f[cur][j+1][k]+=f[!cur][j][k]*(j+1-c[i]);
			}
		for(int j=0;j<=i;++j)
			for(int k=0;k<=i;++k)
				f[cur][j][k]%=mod;
		if(c[i+1]!=c[i])
		{
			memset(f[!cur],0,sizeof f[!cur]);
			for(int j=0;j<=i;++j)
				for(int k=0;k<=i;++k)
					f[!cur][j][0]=(f[!cur][j][0]+f[cur][j][k]*inv[k+1])%mod;
			cur^=1;
		}
	}
	cur^=1;
	for(int j=0;j<=n-m;++j)
		ans=(ans+f[cur][j][0]*fac[n])%mod;
	cout<<ans;*/
	int cur=1;
	for(int tt=0;tt<=n;++tt)
	{
		memset(f,0,sizeof f);
		f[0][tt][0]=1,cur=1;
		for(int i=n;i>=1;cur^=1,--i)
		{
			memset(f[cur],0,sizeof f[cur]);
			for(int j=0;j<=tt;++j)
			{
				for(int k=0;k<=tt;++k)
				{
					f[cur][j][k]+=f[!cur][j+1][k];
					if((n-t[j]-(n-i-(tt-j-1-k)))>0)
						f[cur][j][k+1]+=f[!cur][j+1][k]*(n-t[j]-(n-i-(tt-j-1-k)));
					if((n-t[j]-(n-i-(tt-j-k)))>0)
						f[cur][j][k]+=f[!cur][j][k]*(n-t[j]-(n-i-(tt-j-k)));
				}
			}
			for(int j=0;j<=n;++j)
				for(int k=0;k<=n;++k)
					f[cur][j][k]%=mod;
		}
		cur^=1;
		for(int i=0,v=1;i<=tt;++i,v=-v)
			ans=(ans+v*f[cur][0][i]*fac[tt-i])%mod;
	}
	cout<<(ans+mod)%mod<<'\n';
}
void baoli()
{
	g[0][0]=1;
	for(int i=1;i<(1<<n);++i)
	{
		for(int j=0;j<n;++j)
			if((i>>j)&1)
			{
				for(int k=0;k<n;++k)
				{
					g[i][k+(c[j+1]<=k||s[popcount(i)]=='0')]=(g[i][k+(c[j+1]<=k||s[popcount(i)]=='0')]+g[i-(1<<j)][k])%mod;
				}
			}
	}
	ans=0;
	for(int j=0;j<=n-m;++j)
		ans=(ans+g[(1<<n)-1][j])%mod;
	cout<<ans<<'\n';
}
void M()
{
	ans=fac[cnt[0]];
	/*dp[0][0]=1;
	for(int i=1;i<=n;cur^=1,++i)
	{
		memset(dp[cur],0,sizeof dp[cur]);
		if(s[i]=='1')
		{
			for(int j=0;j<=i;++j)
				dp[cur][j+1]
		}
		else
			for(int j=0;j<=i;++j)
				dp[cur][j+1]=dp[!cur][j];
	}*/
	int c=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='1')
			ans=ans*max(0,t[i-1]-i+1+c)%mod;
		else
			++c;
	cout<<(fac[n]-ans+mod)%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cin>>s+1;
	fac[0]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i)
		++cnt[s[i]-'0'],fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;++i)
		cin>>c[i],++t[c[i]];
	sort(c+1,c+1+n);
	for(int i=1;i<=n;++i)
		t[i]+=t[i-1];
	if(n<=18)
	{
		baoli();
	}
	else if(m==1)
		M();
	else if(m==n)
	{
		if(cnt[1]==n&&t[0]==0)
			cout<<fac[n];
		else
			cout<<"0";
	}
	else if(cnt[1]==n)
		solve();
	else
	{
		
	}
	return 0;
}
