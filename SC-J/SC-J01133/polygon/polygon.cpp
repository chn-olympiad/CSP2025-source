#include <bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 998244353;

int n, m;
int a[N], dp[N][N];

int fastPow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (1ll * res * a) % mod;
		a = (1ll * a * a) % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		m = max(m, a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= m; i++)
		dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < a[i]; j++)
			dp[i][j] = dp[i - 1][j] % mod;
		for (int j = a[i]; j <= m; j++)
		{
			int t = j - a[i];
			dp[i][j] = (dp[i - 1][t] + dp[i - 1][j]) % mod;
		}
	}
	int ans = fastPow(2, n) - 1;
	for (int i = 1; i <= n; i++)
	{
		ans = ((ans - dp[i - 1][a[i]]) % mod + mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
