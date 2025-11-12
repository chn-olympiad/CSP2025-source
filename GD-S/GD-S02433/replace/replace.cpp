#include <bits/stdc++.h>

using namespace std;
#define i64 long long

const int N = 5e6 + 10;
const int P = 131, mod = 1e9 + 7;

int n, q;
i64 f[2][N], p[N];
map<int, map<int, bool> > mp;

i64 hlr(int o, int l, int r) {
	return ((f[o][r] - f[o][l-1] * p[r-l+1] % mod) % mod + mod) % mod;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 5e6; i++) {
		p[i] = p[i-1] * P % mod;
	}
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		i64 h1 = 0, h2 = 0;
		int m = s.size();
		for (int i = 0; i < m; i++) {
			h1 = (h1 * P % mod + s[i]) % mod;
			h2 = (h2 * P % mod + t[i]) % mod;
		}
		mp[h1][h2] = true;
	}
	while (q--) {
		string s, t;
		cin >> s >> t;
		int m = s.size();
		s = '$' + s, t = '$' + t;
		for (int i = 1; i <= m; i++) {
			f[0][i] = (f[0][i - 1] * P % mod + s[i]) % mod;
			f[1][i] = (f[1][i - 1] * P % mod + t[i]) % mod;
		}
		i64 ans = 0;
		for (int i = 0; i <= m + 1; i++) {
			if (i >= 1 && hlr(0, 1, i) != hlr(1, 1, i)) {
				continue;
			}
			for (int j = i + 2; j <= m + 1; j++) {
				if (j <= m && hlr(0, j, m) != hlr(1, j, m)) {
					continue;
				}
				if (mp[hlr(0, i+1, j-1)][hlr(1, i+1, j-1)]) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
