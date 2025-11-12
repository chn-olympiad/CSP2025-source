#include <bits/stdc++.h>
using namespace std;
int dp[5001], a[5001], mod=998244353, ans=0, maxn=0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	dp[0]=1; 
	for(int i = 1; i<=n; i++)
	{
		ans=(ans+maxn)%mod;
		for(int j = a[i]+1; j<=a[n]; j++)
		{
			ans=(ans+dp[j])%mod;
		}
		maxn=(maxn+maxn)%mod;
		for(int j = a[n]; j>=0; j--)
		{
			if(j+a[i]>a[n])
			{
				maxn=(dp[j]+maxn)%mod;
			}
			else
			{
				dp[j+a[i]]=(dp[j]+dp[j+a[i]])%mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
