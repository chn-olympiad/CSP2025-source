#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio (0), cin.tie (0), cout.tie (0)
#define res register int
#define int long long
#define rep(i, l, r) for (res i = (l); i <= (r); i ++)
#define drep(i, l, r) for (res i = (r); i >= (l); i --)
#define tim clock () * 1.0 / CLOCKS_PER_SEC
#define PII pair <int, int>
#define iv inline void
#define siz(x) (int)x.size ()
#define all(x) x.begin (), x.end ()
#define pb push_back
using namespace std;
const int N = 200005, inf = 1e18;
iv cmax(int &x, int y) { x = x > y ? x : y; }
int n, a[5][N], ans, s[5], p;
vector <int> g[5], f;
iv solve () {
	cin >> n; ans = p = 0; rep(i, 1, 3) g[i].clear (); f.clear ();
	rep(i, 1, n) rep(j, 1, 3) cin >> a[j][i];
	rep(i, 1, n) a[0][i] = max ({a[1][i], a[2][i], a[3][i]}), ans += a[0][i];
	rep(i, 1, n) {
		int ss = 0; rep(j, 1, 3) if (a[j][i] == a[0][i]) ss ++; if (ss > 1) continue;
		if (a[0][i] == a[1][i]) g[1].pb (i);
		if (a[0][i] == a[2][i]) g[2].pb (i);
		if (a[0][i] == a[3][i]) g[3].pb (i);
	}
	rep(i, 1, 3) if (siz(g[i]) > n / 2) p = i;
	if (!p) return cout << ans << '\n', void ();
	for (auto i : g[p]) {
		f.pb (-inf);
		rep(j, 1, 3) if (j ^ p) cmax(f[siz(f) - 1], a[j][i] - a[p][i]);
	}
	sort (all(f)); rep(i, n / 2, siz(f) - 1) ans += f[i];
	cout << ans << '\n';
}
signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	FASTIO;
	int T; cin >> T;
	while (T --) solve ();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
