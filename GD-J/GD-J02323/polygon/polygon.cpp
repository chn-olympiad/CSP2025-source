#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n;
int a[N];
int ans;
int dp[N];
void dfs(int x,int s,int m)
{
	if(x==n+1)
	{
		if(s>m*2)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(x+1,s,m);
	dfs(x+1,s+a[x],max(m,a[x]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans%mod;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=(dp[i]+dp[i-1])%mod;
		for(int j=i-2;j>=1;j--)
		{
			int s=0,m=0;
			for(int k=i;k>=j;k--)
			{
				m=max(m,a[k]);
				s+=a[k];
			}
			if(s>m*2)
			{
				dp[i]=(dp[i]+dp[j-1]+1)%mod;
			}
		}
	}
	cout<<dp[n]%mod;
	return 0;
}
