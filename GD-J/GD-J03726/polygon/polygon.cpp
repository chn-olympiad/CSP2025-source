#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[N], ma, sum, ans = 0, total_sum = 0, total_ma = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total_sum += a[i];
		total_ma = max(total_ma, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ma = 0, sum = 0;
			for (int k = i; k <= j; k++) {
				ma = max(ma, a[k]);
				sum += a[k];
			}
			if (sum > 2 * ma) {
				ans++;
				ans %= 998;
				ans %= 244;
				ans %= 353;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ma = 0, sum = 0;
			for (int k = i; k <= j; k++) {
				ma = max(ma, a[k]);
				sum += a[k];
			}
			if (i != 1 && j != n && total_sum - sum > 2 * total_ma) {
				ans++;
				ans %= 998;
				ans %= 244;
				ans %= 353;
			}
		}
	}
	cout << ans;
	return 0;
}

