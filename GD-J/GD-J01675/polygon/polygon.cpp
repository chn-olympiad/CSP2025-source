#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005],dp[50005][505];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=25)
	{
		long long ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			int sum=0,ma=0;
			for(int j=1;j<=n;j++)
			{
				int cur=1<<j-1;
				if(i&cur)
				{
					sum+=a[j];
					ma=max(ma,a[j]);
				}
			}
			if(sum>2*ma)ans++;
		}
		cout<<ans;
	}
	else if(n<=500)
	{
		int sum=0,ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			sum+=a[i];
		dp[0][0]=1;
		for(int i=a[1]+a[2]+a[3];i<=sum;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i<=2*a[j])continue;
				dp[i][j]+=dp[i-a[j]][j],ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
	}
	return 0;
}
