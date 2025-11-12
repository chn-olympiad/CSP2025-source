#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=505,M=5e4+5,mod=998244353;
int n,a[N],dp[N][M],pre[N],ans;

int dfs(int dep,int x,int s)
{
	if(dp[x][s])
	  return dp[x][s];
	int res=0;
	if(s>a[x]*2 && dep>=3)
	  res++;
	for(int i=x+1;i<=n;i++)
	  res=(res+dfs(dep+1,i,s+a[i]))%mod;
	return dp[x][s]=res%mod;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	  ans=(ans+dfs(1,i,a[i]))%mod;
	return !(cout<<ans<<'\n');

//	for(int i=1;i<=n;i++)
//	  pre[i]=pre[i-1]+a[i];
//	for(int i=1;i<=n;i++)
//	  dp[i][0]=1;
//	for(int i=3;i<=n;i++)
//		for(int j=0;j<=pre[n];j++)
//		{
////			dp[i][j]=dp[i-1][j];
//			if(j-a[i]>=0 && j>a[i]*2 && j<=pre[i])
//			  dp[i][j]=max(dp[i][j],(dp[i][j]+dp[i-1][j-a[i]])%mod);
//		}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=30;j++)
//		  printf("%lld ",dp[i][j]);
//		puts("");
//	}
//	return !printf("%lld\n",dp[n][pre[n]]);
}
