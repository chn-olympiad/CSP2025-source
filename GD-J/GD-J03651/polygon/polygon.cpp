#include <bits/stdc++.h>
using namespace std;
int const mod = 998244353;
int n, a[5005], dp[5005][5005], v[5005][5005], mx[5005][5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	if(n < 3)
	{
		cout<<0;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 2; j < n; j++)
		{
			dp[i][j] = dp[i][j - 1];
			mx[i][j] = max(mx[i][j], mx[i][j] + a[j]);
			v[i][j] = v[i][j - 1] + a[j];
			if(v[i][j] > mx[i][j] * 2) dp[i][j] = (dp[i][j] + 1) % mod;
		}
	}
	cout<<dp[n - 1][n - 1];
	return 0;
}
