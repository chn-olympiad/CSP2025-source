#include <bits/stdc++.h>
using namespace std;

#define int long long
#ifndef LOCAL_TEST
#define endl '\n'
#endif

int n, q;

namespace bruteforce {
	const int MAXN = 2e3 + 5, mod = 1e9 + 7;
	const int base = 233, N = 2e3;
	unordered_map<int, int> cnt;
	int pw[MAXN], inv[MAXN];

	int quickpow(int a, int b) {
		int ret = 1;
		while (b) {
			if (b & 1) ret = ret * a % mod;
			a = a * a % mod; b >>= 1;
		}
		return ret;
	}

	void work() {
		for (int i = 1; i <= n; ++i) {
			string s, t;
			cin >> s >> t;
			int sh = 0, th = 0;
			for (int j = 0; j < (int)s.size(); ++j) {
				sh = (sh * base + s[j] - 'a' + 1) % mod;
				th = (th * base + t[j] - 'a' + 1) % mod;
			}
			cnt[(sh * base + th) % mod]++;
		}
		pw[0] = 1;
		for (int i = 1; i <= N; ++i) {
			pw[i] = pw[i - 1] * base % mod;
		}
		inv[N] = quickpow(pw[N], mod - 2);
		for (int i = N - 1; i >= 0; --i) {
			inv[i] = inv[i + 1] * base % mod;
		}
		for (int i = 1; i <= q; ++i) {
			string s, t;
			cin >> s >> t;
			if (s.size() != t.size()) {
				cout << 0 << endl;
				continue;
			}
			int m = s.size();
			s = ' ' + s;
			t = ' ' + t;
			int dl = 0, dr = m + 1;
			for (int j = 1; j <= m; ++j) {
				if (s[j] != t[j]) {
					dl = j; break;
				}
			}
			for (int j = m; j >= 1; --j) {
				if (s[j] != t[j]) {
					dr = j; break;
				}
			}
			vector<int> sh(m + 2), th(m + 2);
			for (int j = 1; j <= m; ++j) {
				sh[j] = (sh[j - 1] * base + s[j] - 'a' + 1) % mod;
				th[j] = (th[j - 1] * base + t[j] - 'a' + 1) % mod;
			}
			// cerr << "dl=" << dl << ' ' << "dr=" << dr << endl;
			int ans = 0;
			for (int j = dr + 1; j <= m + 1; ++j) {
				for (int k = dl - 1; k >= 0; --k) {
					int len = j - k - 1;
					int nows = (sh[j - 1] - sh[k] * pw[len] % mod + mod) % mod;
					int nowt = (th[j - 1] - th[k] * pw[len] % mod + mod) % mod;
					if (cnt.find((nows * base + nowt) % mod) != cnt.end())
						ans += cnt[(nows * base + nowt) % mod];
					// cerr << nows << ' ' << nowt << endl;
					// cerr << j << ' ' << k << ' ' << cnt[(nows * base + nowt) % mod] << endl;
				}
			}
			cout << ans << endl;
		}
	}
}

void work() {
	cin >> n >> q;
	return bruteforce::work();
}

signed main(void) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	work();
	return 0;
}
