#include<bits/stdc++.h>
using namespace std;
const int N	= 5005, T = 5e5 + 5, mod = 998244353;
int n, sum, ans, a[N], dp[T];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 3;i <= n;i++)
	{
		sum = 0;
		for(int j = 1;j < i;j++) sum += a[j];
		for(int i = 1;i <= sum;i++) dp[i] = 0;
		dp[0] = 1;
		for(int j = 1;j < i;j++)
			for(int k = sum;k >= a[j];k--)
				dp[k] = (dp[k] + dp[k - a[j]]) % mod;
		for(int j = a[i] + 1;j <= sum;j++)
			ans = (ans + dp[j]) % mod;
	}
	cout << ans << "\n";
	return 0;
}
