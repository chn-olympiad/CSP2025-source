#include <bits/stdc++.h>
#define add(x,y) x=((x)+(y))%mod
#define ll long long
using namespace std;
const int N=510;
const ll mod=998244353;
int n,m;
char s[N];
int c[N];
ll dp[2][N][N];
int pre[N],num[N];
ll fac[N],inv[N];
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=ksm(fac[i],mod-2);
	}
	for(int i=1;i<=n;++i)
	{
		++pre[c[i]];
	}
	for(int i=1;i<=n;++i)
	{
		pre[i]+=pre[i-1];
	}
	for(int i=1;i<=n;++i)
	{
		num[i]=(s[i]=='0');
	}
	for(int i=1;i<=n;++i)
	{
		num[i]+=num[i-1];
	}
}
void work()
{
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		int nxt=(i&1);
		int now=!nxt;
		memset(dp[nxt],0,sizeof(dp[nxt]));
		if(s[i]=='0')
		{
			for(int j=0;j<=n;++j)
			{
				for(int k=0;k<=n;++k)
				{
					dp[nxt][j][k]=dp[now][j][k];
				}
			}
			continue ;
		}
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				// 情况一 该位置爆炸成 0
				// 此情况不用容斥
				add(dp[nxt][j+1][k+1],dp[now][j][k]*(pre[j+num[i]]-k+mod)%mod);
				
				// 情况二 该位置没有爆炸
				// 需要容斥一下
				add(dp[nxt][j][k],dp[now][j][k]);
				
				add(dp[nxt][j][k+1],dp[now][j][k]*(mod-1)%mod*(pre[j+num[i]]-k+mod)%mod); 
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=n;++j)
	{
		for(int k=0;k<=n;++k)
		{
			if(n-num[n]-j<m)
				continue ;
			add(ans,dp[n&1][j][k]*fac[n-k]%mod);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
	}
	init();
	work();
	return 0;
}












