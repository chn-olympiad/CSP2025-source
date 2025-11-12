#include<bits/stdc++.h>
#define ll long long
#define N 5*(int)(1e5+10)
using namespace std;

ll n,k,cnt;
ll a[N],dp[N],vis[N],ans;
ll dfs(ll x,ll dep)
{
	cnt++;
	if(vis[x])
	{
		return dp[x];
	}
	vis[x]=1;
	if(x==n)
	{
		return dp[n]=(a[n]==k);
	}
	if(x>n)
		return 0;
	if(dep>=100000||cnt>=100000000)
	{
		printf("%lld",ans);
		exit(0);
	}
	ll sum=dfs(x+1,dep+1);
	ll val=0;
	for(ll i=x; i<=n; i++)
	{
		val=val xor a[i];
		if(val==k)
			sum=max(sum,dfs(i+1,dep+1)+1);
	}
	return dp[x]=sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(ll i=1; i<=n; i++)
	{
		scanf("%lld",a+i);
	}
	vis[1]=1;
	ans=dfs(1+1,1);
	ll val=0;
	for(ll i=1; i<=n; i++)
	{
		val=val xor a[i];
		if(val==k)
			ans=max(ans,dfs(i+1,1)+1);
	}
	printf("%lld",ans);
    return 0;
}

