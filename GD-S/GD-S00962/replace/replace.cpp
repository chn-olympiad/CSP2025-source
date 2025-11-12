#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int MOD = 998244353;

int n, q;
string u, v;
map <int, int> g;

int qpow (int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a % MOD;
	int t = qpow (a, b / 2) * qpow (a, b / 2) % MOD;
	if (b % 2 == 0) return t;
	return t * a % MOD;
}

int change (int x, int y) {
	return qpow (17, x) * qpow (19, y);
}

signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	while (n --) {
		cin >> u >> v;
		int l = 0, r = 0;
		for (int i = 0; i < u.size (); i ++) {
			l = (l * 37 % MOD + (u[i] - 'a' + 1) % MOD) % MOD;
			r = (r * 37 % MOD + (v[i] - 'a' + 1) % MOD) % MOD;
		}
		g[change (l, r)] ++;
	}
	while (q --) {
		cin >> u >> v;
		int first, end, ans = 0;
		if (u.size () != v.size ()) {
			cout << 0 << "\n"; continue;
		}
		for (int i = 0; i < u.size (); i ++)
			if (u[i] != v[i]) end = i;
		for (int i = u.size () - 1; i >= 0; i --)
			if (u[i] != v[i]) first = i;
		for (int i = 0; i <= first; i ++) {
			int l = 0, r = 0;
			for (int j = i; j < u.size (); j ++) {
				l = (l * 37 % MOD + (u[j] - 'a' + 1) % MOD) % MOD;
				r = (r * 37 % MOD + (v[j] - 'a' + 1) % MOD) % MOD;
				if (j >= end) ans += g[change (l, r)];
			}	
		}	
		cout << ans << "\n";
	}
	return 0;
}
