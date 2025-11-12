#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, a[N], b[N], cnt, k, ans, t[N], dp[N], mn = 0, bg = 0, fl = 1;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0 || k == 0) b[++cnt] = a[i];
		if (a[i] == 1) bg++;
		if (a[i] > 1) fl = 0;
	}
	if (k == 1 && fl) {
		cout << bg;
		return 0;
	}
	for (int i = 1; i <= cnt; i++) t[i] = t[i - 1] ^ b[i];
	for (int i = 1; i <= cnt; i++) {
		dp[i] = dp[i - 1];
		for (int j = mn; j <= i; j++) {
			if (i == j) {
				if (b[i] == k) {
					dp[i] += 1;
					mn = i;
				}
				break;
			}
			if ((t[j] ^ t[i]) != k) continue;
			dp[i] += 1;
			mn = i;
			break;
		}
	}
	cout << dp[cnt];
	return 0;
}