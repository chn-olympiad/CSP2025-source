#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], sum[5005];
long long dp[5005], c[5005], ans;
void ch()
{
	c[1]=1;
	for(int i=2; i<=n; i++)
	{
		c[i]=c[i-1]*i%MOD;
	}
	return ;
}
int A(int i, int j)
{
	int ansa=c[i]/c[i-j]%MOD;
	return max(0, ansa);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	
	int i, j, k;
	cin>>n;
	ch();
	for(i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(i=1; i<=n; i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	dp[1]=0;
	dp[2]=0;
	if(n==3)
	{
		if(sum[3]>a[3]*2)
			dp[3]=1;
		cout<<dp[n];
		return 0;
	}
	for(i=3; i<=n; i++)
	{
		for(j=i-1; j>=1; j--)
		{
			for(k=j-1;k>=1;k--)
			{
				if(sum[i]-sum[j]>=sum[k])
					dp[j]=(max(dp[i], dp[j]+A(j, k)))%MOD;
			}
			dp[i]=max(dp[i-1], dp[j]);
		}
		ans = max(ans, dp[i]);
	}
	cout<<ans;
	return 0;
}
