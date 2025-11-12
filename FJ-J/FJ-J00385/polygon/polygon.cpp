#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long dp[5000][2500],ans,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	for(long long j=sum;j>=1;j--)
	{
		dp[i][j]=dp[i-1][j];
		if(j>=a[i])
		dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%998244353;
		if(j>2*a[i])
		ans=(ans+dp[i-1][j-a[i]])%998244353;
	}
	cout<<ans;
	return 0;
}
