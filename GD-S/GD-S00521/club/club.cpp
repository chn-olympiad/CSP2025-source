#include<bits/stdc++.h>
using namespace std;
int dp[4][10001],cnt[4],ans,n,x,t;
void dfs(int idx,int num)
{
	if(idx==n)
	{
		ans=max(ans,num);
		return ;
	}
	if(cnt[1]<x)
	{
		cnt[1]++;
		dfs(idx+1,num+dp[1][idx+1]);
		cnt[1]--;
	}
	if(cnt[2]<x)
	{
		cnt[2]++;
		dfs(idx+1,num+dp[2][idx+1]);
		cnt[2]--;
	}
	if(cnt[3]<x)
	{
		cnt[3]++;
		dfs(idx+1,num+dp[3][idx+1]);
		cnt[3]--;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		x=n/2;
		for(int i=1;i<=n;i++)
			cin>>dp[1][i]>>dp[2][i]>>dp[3][i];
		dfs(0,0);
		cout<<ans<<endl;
	}
} 
