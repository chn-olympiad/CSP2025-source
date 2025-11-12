#include <bits/stdc++.h>

const long long mod = 998244353;
bool f = true;
long long n, sum = 0, mx = 0, nmx = 0, ans = 0, res = 6, rr = 1;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%lld", &n);
	std::vector <long long> a (n + 5, 0);
	
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i], mx = std::max(mx, a[i]);
	}
	
	for (long long i = 1; i <= n; i++) {
		if (a[i] != 1) {
			f = false;
		}
	}
	if (n <= 3) {
		if (a[3] + a[1] > a[2] && a[3] + a[2] > a[1] && a[1] + a[2] > a[3]) {
			printf("1");
			return 0;
		} else {
			printf("0");
			return 0;
		}
	}
	if (f) {
		for (long long i = 3; i <= n; i++) {
			rr = 1;
			for (long long j = n; j >= n - i + 1; j--) {
				rr *= j;
			}
			for (long long j = 1; j <= i; j++) {
				rr /= j;
			}
			ans += rr;
			ans %= mod;
		}
		printf("%lld", rr);
		return 0;
	}
	
	//dp[i][k] -> 前i根木棍, 差为k 
	std::vector < long long > dp[2];
	dp[0] = std::vector < long long > (mx + 5, 0);
	dp[1] = std::vector < long long > (mx + 5, 0);
	
	dp[0][0] = 1; dp[1][0] = 1;
	for (long long i = 1; i <= n; i++) {
		for (long long k = mx; k >= 0; k--) {
			if (k > a[i]) 
				dp[1][k] = (dp[1][k - a[i]] + dp[0][k - a[i]]) % mod;
			dp[0][k] = (dp[1][k] + dp[0][k]) % mod;
		}
	}
	for (long long k = 0; k <= mx; k++) {
		ans += dp[1][k] + dp[0][k];
		ans %= mod;
	}
	printf("%lld", ans);
	return 0;
} 