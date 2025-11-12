#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005, mod = 998244353;
int n, a[N], f[N], ans = 1;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; ans = ans * 2ll % mod;
	} sort(a + 1, a + n + 1); f[0] = 1, ans = (ans - 1ll + mod) % mod;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= a[i]; j++) ans = (ans - f[j] + mod) % mod;
		for (int j = 5000; j >= a[i]; j--) f[j] = (f[j] + f[j - a[i]]) % mod;
	} cout << ans;
	return 0;
}
