#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, k, a[500005], pre[500005];

map <int, int> mp;

int qan[500005], dp[500005];

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	mp[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		pre[i] = (pre[i - 1] ^ a[i]);
		qan[i] = -1;
		if (a[i] == k) {
			qan[i] = i;
		} else if (mp.count(pre[i] ^ k)) {
			qan[i] = mp[pre[i] ^ k] + 1;
		}
		mp[pre[i]] = i;
	}
	for (int i = 1; i <= n; ++ i) {
		dp[i] = dp[i - 1];
		if (qan[i] != -1) {
			dp[i] = max(dp[i], dp[qan[i] - 1] + 1);
		}
	}
	cout << dp[n];
	return 0;
}