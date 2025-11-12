#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005][5005],mod=998244353;
bool f[5005][5005];
int dfs(int c,int d)
{
	if(d>n)return 0;
	if(f[c][d])
	{
		return dp[c][d];
	}
	int cnt=0;
	for(int i=d+1;i<=n;i++)
	{
		if(c>a[i])
		{
			cnt=(cnt+1)%mod;
		}
		cnt=(cnt+dfs(c+a[i],i))%mod;
	}
	f[c][d]=1;
	dp[c][d]=cnt;
	return cnt;
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
	sort(a+1,a+n+1);
	int ans=dfs(0,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
