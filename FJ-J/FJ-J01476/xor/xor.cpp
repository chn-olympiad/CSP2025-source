#include <bits/stdc++.h>
using namespace std;
int f[500010], pos, cnt, dp[500010], ans;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a;
	cin >> n >> k;
	int fz = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		f[i] = f[i - 1] ^ a;
		fz |= a;
	}
	if ((fz | k) != fz) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = n; i > 0; i--) {
		if (i != n) {
			dp[i] = dp[i + 1];
		}
		for (int j = i; j <= n; j++) {
			if ((f[i - 1] ^ f[j]) == k) {
				dp[i] = max(dp[i], dp[j + 1] + 1);
				break;
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;*/
	/*for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;*/
	cout << dp[1];
}

