#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, M = 25, MOD = 998244353;
int c[M], a[N], ans, n, dp[N][N];

void dfs(int cur) {
	if (cur > n) {
		int maxn = 0, sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			maxn = max(maxn, a[i] * c[i]);
			sum += (a[i] * c[i]);
			cnt += c[i];
		}
		ans += (sum > 2 * maxn && cnt >= 3);
		return;
	}
	c[cur] = 0;
	dfs(cur + 1);
	c[cur] = 1;
	dfs(cur + 1);
}

long long fpow(long long a, long long b) {
	long long ret = 1;
	for (; b; a = a * a % MOD, b >>= 1)
		if (b & 1)
			ret = ret * a % MOD;
	return ret;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 20) {
		dfs(1);
		cout << ans << '\n';
		return 0;
	}
	if (a[n] <= 1) {
		cout << (fpow(2, n) - 1 - n - (n * (n - 1) / 2)) % MOD << '\n';
		return 0;
	}
	return 0;
}
