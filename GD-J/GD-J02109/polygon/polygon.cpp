#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans,dp[5005];
void dfs(int k,int now,int last,int maxx,int sum)
{
	if(now==k)
	{
		if(sum>maxx*2) ans++;
		ans%=mod;
		return ;
	}
	for(int i=last+1;i<=n;i++)
	{
		dfs(k,now+1,i,max(maxx,a[i]),sum+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(i,0,0,0,0);
	}
	cout<<ans%mod;
	return 0;
}
