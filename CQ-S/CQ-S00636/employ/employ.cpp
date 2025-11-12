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
const int N = 505, P = 998244353;
iv cmin(int &x, int y) { x = x < y ? x : y; }
iv cadd(int &x, int y) { x = x + y >= P ? x + y - P : x + y; }
int n, m, a[N], vis[N], ans, ss, ret = 1;
string s;
void dfs (int x, int s0) {
	if (x > n) {
		if (n - s0 >= m) cadd(ans, ret);
		return ;
	}
	if (s[x] == '0') return dfs (x + 1, s0 + 1);
	rep(i, 1, n) if (!vis[i]) {
		vis[i] = 1;
		dfs (x + 1, s0 + (s0 >= a[i]));
		vis[i] = 0;
	}
}
iv solve () {
	cin >> n >> m >> s; s = " " + s;
	rep(i, 1, n) cin >> a[i], ss += s[i] == '0';
	rep(i, 1, ss) ret = ret * i % P;
	sort (a + 1, a + 1 + n, [&] (int x, int y) { return x > y; });
	dfs (1, 0);
	cout << ans << '\n';
}
signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	FASTIO;
	int T = 1; //cin >> T;
	while (T --) solve ();
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
