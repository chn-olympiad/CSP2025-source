#include <bits/stdc++.h>
using namespace std;
int lst[500010], a[500010], dp[500010], n, k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int tmp = a[i];
		if (tmp == k) {
			lst[i] = i - 1;
			continue;
		}
		lst[i] = -1;
		for (int j = i - 1; j >= 1; j--) {
			tmp ^= a[j];
			if (tmp == k) {
				lst[i] = j - 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (lst[i] != -1) dp[i] = max(dp[i], dp[lst[i]] + 1);
	}
	cout << dp[n];
	return 0;
}
