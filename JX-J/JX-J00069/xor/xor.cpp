#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,dp[500010],ans;
struct sp{
	int l,r;
}d[500010];
void dfs(int step,int cnt)
{
	if(step>n)
	{
		ans=max(cnt,ans);
		return ;
	}
	dfs(step+1,cnt);
	for(int i=step;i<=n;i++)
	{
		if((dp[i] xor dp[step-1])==k) 
		{
			dfs(i+1,cnt+1);
		}
		if(i==n) dfs(n+1,cnt);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];dp[i]=dp[i-1] xor a[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
