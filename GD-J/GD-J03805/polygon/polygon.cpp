#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int mod = 998244353;
const int N = 5005;
inline int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
	return res;
}
int n, a[N], ans, fac[N], inv[N], mx;
inline int C(int a, int b) {
	return fac[a] * inv[b] % mod * inv[a - b] % mod;
}
void dfs(int x, int sum, int tmp) {
	if (x > n) {
		if (sum > 2 * tmp) ans++;
		if (ans >= mod) ans -= mod;
		return ;
	}
	dfs(x + 1, sum + a[x], max(tmp, a[x]));
	dfs(x + 1, sum, tmp);
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
	inv[N - 1] = qpow(fac[N - 1], mod - 2);
	for (int i = N - 2; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
	if (mx == 1) for (int i = 3; i <= n; i++) ans = (ans + C(n, i)) % mod;
	else dfs(1, 0, 0);
	cout << ans;
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
