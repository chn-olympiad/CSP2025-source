#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, mod = 998244353;
int n, q, f[N][2], g[N][2], t[N][2], p[N]; string s1[N], s2[N], t1, t2;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q; p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = p[i - 1] * 233ll % mod; 
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i]; int cnt = 0;
		for (char c : s1[i]) t[i][0] = (t[i][0] + p[cnt ++] * (c - 'a') % mod) % mod;
		cnt = 0;
		for (char c : s2[i]) t[i][1] = (t[i][1] + p[cnt ++] * (c - 'a') % mod) % mod;
	}
	while(q --) {
		cin >> t1 >> t2;
		f[(int)t1.size()][1] = g[(int)t1.size()][1] = 0;
		for (int i = 0; i < (int)t1.size(); i++) {
			f[i][0] = (f[i - 1][0] + p[i] * (t1[i] - 'a') % mod) % mod;
			g[i][0] = (g[i - 1][0] + p[i] * (t2[i] - 'a') % mod) % mod;
		}
		for (int i = (int)t1.size() - 1; i >= 0; i--) {
			f[i][1] = (f[i + 1][1] + p[i] * (t1[i] - 'a') % mod) % mod;
			g[i][1] = (g[i + 1][1] + p[i] * (t2[i] - 'a') % mod) % mod;
		} int ans = 0;
		for (int i = 1; i <= n; i++) {
			int o = (int)s1[i].size();
			for (int j = 0; j + o - 1 < (int)t1.size(); j++) {
				if((f[j + o - 1][0] - f[j - 1][0] + mod) % mod == t[i][0] * p[j] % mod) {
					if((f[j - 1][0] + t[i][1] * p[j] % mod + f[j + o][1]) % mod == g[(int)t1.size() - 1][0]) ans ++;
				}
			}
		} cout << ans << '\n';
	}
	return 0;
}
