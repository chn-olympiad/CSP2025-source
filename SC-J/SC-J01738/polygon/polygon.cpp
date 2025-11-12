#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, maxn = 5010;
int a[maxn];
int n;
int ans = 0;
void dfs(int start, int zong, int maxlen, int bian) {
	if (bian == 0) {
		if (zong > maxlen * 2) {
			ans++;
			ans = ans % mod;
		}
		return;
	}
	if (start == n) return;
	for (int i = start + 1; i <= n; i++) {
		dfs(i, zong + a[i], max(maxlen, a[i]), bian - 1);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	bool flag = true;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1) flag = false;
		cin >> a[i];
	}
	if (flag) {
		long long num = 0;
		for (int i = 3; i <= n; i++) {
			for (int j = 3; j <= n; j++) {
				long long x = 1, y = 1;
				for (int l = j; l >= j - i; l--) {
					x *= l;
					x %= mod;
				}
				for (int l = 1; l <= i; l++) {
					y *= l;
					y %= mod;
				}
				num += (x / y);
				num %= mod;
			}
		}
		cout << num;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		dfs(0, 0, 0, i);
	}
	cout << ans % mod;
	return 0;
}