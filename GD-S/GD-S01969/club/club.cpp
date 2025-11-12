#include <bits/stdc++.h>

#define il inline

#define dbg(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

using ll = long long;

const int N = 1e5;

vector<int> a[N + 5];
int n, ans, f[3];

il void upd(vector<int> &u) {
	int mxu = -1, seu = -1, p = 0, q = 0;
	for (int i = 0; i < 3; i++) {
		int x = u[i];
		if (mxu < x) seu = mxu, mxu = x, q = p, p = i;
		else if (seu < x) seu = x, q = i;
	}
	u.emplace_back(p), u.emplace_back(q);
}

void solve() {
	scanf("%d", &n);
	ans = 0, memset(f, 0, sizeof f);
	int x = 1, y = 1;
	for (int i = 1; i <= n; i++) {
		a[i].resize(3);
		for (auto &u : a[i]) scanf("%d", &u);
		x &= !a[i][1], y &= !a[i][2];
	}
	if (x && y) {
		sort(a + 1, a + n + 1);
		for (int i = n / 2 + 1; i <= n; i++)
			ans += a[i][0];
	} else if (y) {
		sort(a + 1, a + n + 1, [&](const vector<int> &u, const vector<int> &v) {
			return abs(u[0] - u[1]) > abs(v[0] - v[1]);
		});
		for (int i = 1; i <= n; i++) {
			int p = a[i][0] > a[i][1] ? 0 : 1;
			if (f[p] < n / 2) ans += a[i][p], f[p]++;
			else ans += a[i][!p], f[!p]++;
		}
	} else {
		for (int i = 1; i <= n; i++) upd(a[i]);
		sort(a + 1, a + n + 1, [&](const vector<int> &u, const vector<int> &v) {
			return u[u[u.size() - 2]] - u[u[u.size() - 1]] > v[v[v.size() - 2]] - v[v[v.size() - 1]];
		});
//		for (int i = 1; i <= n; i++) {
//			for (auto u : a[i]) dbg("%d ", u);
//			dbg("\n");
//		}
		for (int i = 1; i <= n; i++) {
			int p = a[i][3], q = a[i][4];
			if (f[p] < n / 2) ans += a[i][p], f[p]++;
			else ans += a[i][q], f[q]++;
//			dbg("%d %d\n", p, q);
		}
	}
	printf("%d\n", ans);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

/*
1
2
10 9 0
6 4 0
*/
