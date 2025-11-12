#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
int n, a[N], ans;
bool flag[N];
void dfs (int k, int s, int g, int mx, int b) {
	if (k >= 2 && s > g) {
		ans ++;
		ans %= mod;
	}
	if (k >= mx) return;
	for (int i = b; i <= mx; i ++) {
		if (flag[i]) continue;
		flag[i] = 1;
		dfs (k + 1, s + a[i], g, mx, i + 1);
		flag[i] = 0;
	}
}
int sum, f[N];
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == n) {
		f[3] = 1, f[4] = 5;
		for (int i = 5; i <= n; i ++) {
			f[i] = (3 * f[i - 1] - 2 * f[i - 2] + i - 2) % mod; 
		}
		cout << f[n] << endl;
		return 0;
	}
	sort (a + 1 , a + 1 + n);
	for (int i = 2; i < n; i ++) {
		dfs (0, 0, a[i + 1], i, 1);
	}
	cout << ans << endl;
}
