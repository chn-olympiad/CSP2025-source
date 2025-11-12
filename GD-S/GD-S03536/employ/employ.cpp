#define ffopen(s) \
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); \
if (*#s) freopen(#s ".in", "r", stdin); \
if (*#s) freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
using intl = long long;
const intl N = 500, Mod = 998244353;
int n, m, a[N + 10];
bitset<N + 10> g;
namespace Task1 {
	bool isTask1() { return n <= 18; }
	vector<int> f[23];
	vector<int> Tset[23];
	void slove() {
		int ALL = (1 << n) - 1;
		for (int j = 0; j <= n; j++) {
			f[j].resize(ALL + 5);
		}
		for (int T = 0; T <= ALL; T++) {
			int cnt = 0;
			for (int p = 1; p <= n; p++) {
				if ((~T) >> (p - 1) & 1) ++cnt;
			}
			Tset[cnt].push_back(T);
		}
		f[0][ALL] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; ~j; j--) {
				for (int T : Tset[i - 1]) {
					for (int p = 1; p <= n; p++) {
						if ((~T) >> (p - 1) & 1) continue;
						int cur = (1 << (p - 1));
						if (g[i]) {
							if (a[p] <= i - j - 1) {
								f[j][T ^ cur] += f[j][T];
								f[j][T ^ cur] %= Mod;
							} else {
								f[j + 1][T ^ cur] += f[j][T];
								f[j + 1][T ^ cur] %= Mod;
							}
						} else {
							f[j][T ^ cur] += f[j][T];
							f[j][T ^ cur] %= Mod;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = m; i <= n; i++) {
			ans += f[i][0];
			ans %= Mod;
		}
		cout << ans % Mod << '\n';
	}
}
void slove() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		g[i] = c == '1';
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (Task1::isTask1()) return Task1::slove();
}
int main() {
	ffopen(employ);
	slove();
	return 0;
}

