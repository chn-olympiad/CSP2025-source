#include <bits/stdc++.h>

using namespace std;

namespace michaele {

	#define rep(i, s, t) for (int i = s; i <= t; i ++)
	typedef long long ll;

	int n, m, K;

	namespace sub1 {

		const int N = 200 + 10, mod = 1e9 + 123, P = 131;


		ll hs[N][2], siz[N];
		ll has[N][N], len[N], has2[N];
		ll pw[N], ipw[N];

		char s[N];

		ll ksm (ll a, ll b) {
			ll res = 1, t = a;
			while (b) {
				if (b & 1) res = res * t % mod;
				t = t * t % mod;
				b >>= 1;
			}
			return res;
		}

		void sol () {
			pw[0] = 1;
			rep (i, 1, N - 1) pw[i] = pw[i - 1] * P % mod;
			rep (i, 0, N - 1) ipw[i] = ksm (pw[i], mod - 2);

			// rep (i, 0, 5) {
			// 	cout << i << ' ' << pw[i] * ipw[i] % mod << endl;
			// }
			rep (i, 1, n) {
				rep (j, 0, 1) {
					scanf ("%s", s + 1);
					siz[i] = strlen (s + 1);
					rep (k, 1, siz[i]) {
						hs[i][j] = (hs[i][j] * P + s[k] - 'a' + 1) % mod;
					}
				}
			}

			rep (i, 1, m) {
				scanf ("%s", s + 1);
				len[i] = strlen (s + 1);
				rep (j, 1, len[i]) {
					has[i][j] = (has[i][j - 1] * P + s[j] - 'a' + 1) % mod;
				}
				scanf ("%s", s + 1);
				rep (j, 1, len[i]) {
					has2[i] = (has2[i] * P + s[j] - 'a' + 1) % mod;
				}
			}

			auto get = [](int i, int l, int r) {
				return ((has[i][r] - has[i][l - 1] * pw[r - l + 1] % mod) % mod + mod) % mod;
			};

			auto calc = [&](int i, int j, int k) {
				ll res = 0;
				res = (has[i][k - 1] * pw[len[i] - (k - 1)] + hs[j][1] * pw[len[i] - (k + siz[j] - 1)]) % mod;
				if (k + siz[j] <= len[i]) res = (res + get (i, k + siz[j], len[i])) % mod;
				return res;
			};

			// cout << get (1, 2, 3) << ' ' << hs[2][0] << endl;
			rep (i, 1, m) {
				ll ans = 0;
			 	rep (j, 1, n) {
			 		if (len[i] < siz[j]) continue;
			 		rep (k, 1, len[i] - siz[j] + 1) {
			 			if (get (i, k, k + siz[j] - 1) == hs[j][0]) {
			 				// cout << i << ' ' << j << ' ' << k << endl;
			 				// cout << calc (i, j, k) << ' ' << has2[i] << endl;
			 				if (calc (i, j, k) == has2[i]) {
			 					ans ++;
			 				}
			 			}
			 		}
			 	}
				cout << ans << '\n';
			}

		}
	}
/*

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
	void solve () {
		cin >> n >> m;
		if (n <= 200) {
			sub1 :: sol ();
		}

	}
}

int main () {
	// freopen ("Cf/replace2.in", "r", stdin);
	// freopen ("Cf/test.out", "w", stdout);
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	
	michaele :: solve ();
	

	return 0;
}