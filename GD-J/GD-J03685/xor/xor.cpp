#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], b[N], dp[N], big;
signed main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = (b[i - 1] ^ a[i]);
		big = max(big, a[i]);
	}
	if (n >= 1000 && k <= 1 && big == 1) {
		int ans = 0;
		bool flag = 0;
		if (k) {
			for (int i = 1; i <= n; ++i)
				if (a[i])
					++ans;
			cout << ans;
		}
		else {
			for (int i = 1; i <= n; ++i) {
				if (!a[i])
					++ans;
				if (a[i] == 1 && a[i - 1] == 1 && !flag)
					flag = 1, ++ans;
				else
					flag = 0;
			}
			cout << ans;
		}
		return 0;
	}
	for (int  i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		for (int j = i; j >= 1; --j) {
			if ((b[i] ^ b[j - 1]) == k) {
				dp[i] = max(dp[i], dp[j - 1] + 1);
			}
		}
	}
	cout << dp[n];
	return 0;
}
