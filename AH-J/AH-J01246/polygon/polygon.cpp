#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans,mx,dp[50005],sum;
void dfs(long long w,long long nowans,long long nowmx)
{
	if (w>n)
	{
		if (nowans>nowmx*2)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(w+1,nowans,nowmx);
	dfs(w+1,nowans+a[w],max(nowmx,a[w]));
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if (n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (i>=3)
		{
			for (int j=sum;j>a[i];j--)
			{
				ans+=dp[j];
				ans%=mod;
			}
		}
		sum+=a[i];
		for (int j=sum;j>=a[i];j--)
		{
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	cout<<ans;
	return 0;
}
