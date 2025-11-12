#include <bits/stdc++.h>
using namespace std;
int a[500010], d[500010];
int len, n, k;
int l[500010], r[500010];
int dp[1000010];
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = d[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if ((d[j] ^ d[i - 1]) == k) {
				l[++len] = i;
				r[len] = j;
			}
		}
	}
	for (int i = len; i >= 1; --i) {
		for (int j = 1; j <= len; ++j) {
			if (l[j] > r[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= len; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans + 1;
	return 0;
}