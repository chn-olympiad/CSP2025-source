#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
ll n, maxx, ans, o = 0;
ll a[N], f[N][N], p[N];
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		maxx = max (maxx, a[i]);
	}
	sort (a + 1, a + n + 1);
	p[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		p[i] = (p[i - 1] * 2) % mod;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= maxx * 2; ++ j) {
			f[i][j] = f[i - 1][j];
			if (j >= a[i]) {
				f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
			} 
		} 
		ll res = p[i - 1] % mod;
		for (int j = 0; j <= a[i]; ++ j) {
			res = (res + mod - f[i - 1][j]) % mod;
		}
		ans = (ans + res) % mod;
	}
	cout << ans % mod << '\n';
	return 0;
}
