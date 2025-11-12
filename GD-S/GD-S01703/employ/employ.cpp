#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e2 + 10;
const int mod = 998244353;

int n, m;

string s;

int c[N], cnt[N], d[N], fac[N];

void solve () {
	cin >> n >> m >> s; s = " " + s;

	fac[0] = 1;
	for (int i = 1 ; i <= n ; i ++) fac[i] = fac[i - 1] * i % mod;

	for (int i = 1 ; i <= n ; i ++) cin >> c[i], cnt[c[i]] ++;

	if (n <= 18) {
		int now = 0, fin = 0;
		for (int i = 1 ; i <= n ; i ++) now = now * 2 + (s[i] - '0');
		
		for (int s = now ; s ; s = (s - 1) & now) {
			int tot = 0;
			for (int i = 1 ; i <= n ; i ++) {
				if (! (s & (1 << (i - 1)))) tot ++;
				else d[i] = tot + 1;
			}
			int ans = 1, ss = 0, r = n;
			for (int i = n ; i >= 1 ; i --) {
				if (s & (1 << (i - 1))) {
					while (r > d[i]) ss += cnt[r --];
					ans = ans * ss % mod;
					ss --;
				}
			}
			ans = ans * fac[tot] % mod;
			fin = (fin + ans) % mod;
		}
		cout << fin << '\n';
	}

}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int t = 1;
	// cin >> t;

	while (t --) solve();
}