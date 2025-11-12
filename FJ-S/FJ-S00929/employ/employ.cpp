#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m,ans;
char c[505];
int a[505],vis[505];
int dp[505][505];
bool f=true;
int dfs(int step,int sum)
{
	if(step==n+1)
	{
		if(n-sum>=m)return 1;
		return 0;
	}
	int cc=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(a[i]<=sum||c[step]=='0')cc+=dfs(step+1,sum+1);
		else cc+=dfs(step+1,sum);
		cc%=mod;
		vis[i]=0;
	}
	dp[step][sum]=cc;
	dp[step][sum]%=mod;
	return dp[step][sum];
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='0')f=false;
	}
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(f)
	{
		int a=1;
		for(int i=1;i<=n;i++)
		{
			a=(ll)(a*i)%mod;
		}
		printf("%d",a);
		return 0;
	}
	ans=dfs(1,0);
	ans%=mod;
	printf("%d",ans);
	return 0;
}

