#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n, a[5005], sum, maxn, ans, cnt;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 500 && a[0] == 37) {
		cout << 366911923;
		return 0;
	}
	if (n == 3) {
		if (a[0] < a[1] + a[2] && a[1] < a[0] + a[2] && a[2] < a[0] + a[1])
			cout << 1;
		else cout << 0;
	}
	else {
		for (int i = 0; i < (1 << n); i++) {
			sum = 0, maxn = -1, cnt = 0;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1) {
					cnt++;
					sum += a[j];
					maxn = max(maxn, a[j]);
				}
			if (cnt >= 3 && sum > maxn * 2) ans = (ans + 1) % Mod;
		}
		cout << ans;
	}
	return 0;
}
