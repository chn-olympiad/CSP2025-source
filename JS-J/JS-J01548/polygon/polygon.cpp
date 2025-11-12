#include<bits/stdc++.h>
typedef long long ll;

const int N = 5100, P = 998244353;

// bool st;
ll A[N];
ll dp[N][N];
// bool ed;

int main() {
	// printf("%lf\n", (&ed - &st) * 1.0 / 1048576);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", A + i);
	std::sort(A + 1, A + 1 + n);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < N; j++) {
			dp[i][j] = dp[i - 1][j];
			(dp[i][j] += dp[i - 1][std::max(j - A[i], 0ll)]) %= P;
		}
	ll ans = 0;
	for(int i = 3; i <= n; i++)
		(ans += dp[i - 1][A[i] + 1]) %= P;
	printf("%lld\n", ans);
	return 0;
}

