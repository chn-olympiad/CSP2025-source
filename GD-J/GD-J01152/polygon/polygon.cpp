#include <bits/stdc++.h>

using namespace std;

const long long N = 5005;
const long long Mod = 998244353;

long long a[N];
long long f[N * 3], g[N * 3];

long long qpow(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % Mod;
		a = a * a % Mod, b >>= 1;
	}
	return res;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	freopen("testcl3.out", "w", stdout);
//	freopen("data.txt", "r", stdin);
//	freopen("WA.txt", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	long long n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	g[0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 2 * a[i]; j >= a[i]; j --) {
			f[j] = (f[j] + g[j - a[i]]) % Mod;
		}
		for (int j = 5000; j >= a[i]; j --) {
			g[j] = (g[j] + g[j - a[i]]) % Mod;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 10000; i ++) {
		ans += f[i]; ans %= Mod;
	}
	cout << ((qpow(2, n) - 1 - ans) % Mod + Mod) % Mod;
	return 0;
}
