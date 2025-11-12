#include <bits/stdc++.h>

#define MAX_N ((int) 5e3)
#define MAX_V ((int) 5e3)
#define MOD (998244353)

int n, a[MAX_N + 1];

int dp[MAX_V + 2], ans = 0;

main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	std::sort(a + 1, a + n + 1);

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = MAX_V + 1; j > a[i]; j--) (ans += dp[j]) %= MOD;
		for (int j = MAX_V + 1; j > MAX_V - a[i]; j--) (dp[MAX_V + 1] += dp[j]) %= MOD;
		for (int j = MAX_V; j >= a[i]; j--) (dp[j] += dp[j - a[i]]) %= MOD;
	}

	printf("%d\n", ans);
	return 0;
}
