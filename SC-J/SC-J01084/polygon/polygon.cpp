#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, MAXN = 5010;
int n, a[MAXN], up[MAXN];
long long f[MAXN][MAXN], pow2[MAXN];
long long ans;
int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);
	if (n < 3) {
		cout << 0;
		return 0;
	}else if (n == 3) {
		if (a[1] + a[2] > a[3]) {
			cout << 1 << endl;
			return 0;
		}else {
			cout << 0;
			return 0;
		}
	}
	f[1][0] = 1, pow2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	for (int i =1; i <= n; i++) {
		f[i][0] = pow2[i] - 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5000; j++) {
			f[i][j] = (f[i - 1][max(j - a[i], 0)] + f[i - 1][j] + (a[i] > j)) % MOD;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans += f[i - 1][a[i]];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}