#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
void solve();
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> p(n + 1);
	vector<int> fa(n + k + 1), q(k + 1);
	vector<vector<bool>> a(n + 1, vector<bool>(k + 1));
	vector<vector<int>> c(k + 1, vector<int>(n + 1));
	vector<vector<array<int, 3>>> G(n + k + 1);
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		array<int, 3> l;
		l[0] = c, l[1] = v, l[2] = 0;
		G[u].push_back(l);
		l[1] = u;
		G[v].push_back(l);
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		q[i + 1] = x;
		int minn = inf, minx = 0, cminn = inf, cminx = 0;
		for (int j = 1; j <= n; j++) {
			int y;
			cin >> y;
			c[i][j] = y;
			if (minn > y) {
				minn = y;
				minx = j;
			} else if (cminn > y) {
				cminn = y;
				cminx = j;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (minx == j) {
				array<int, 3> l;
				l[0] = x + c[i][j] + cminn, l[1] = cminx, l[2] = i + 1;
				G[j].push_back(l);
				continue;
			}
			array<int, 3> l;
			l[0] = x + c[i][j] + minn, l[1] = minx, l[2] = i + 1;
			G[j].push_back(l);
		}
	}
	int ans = 0;
	auto find=[&](auto &find, int x) -> int {
		if (fa[x] == x) return x;
		return fa[x] = find(find, fa[x]);
	};
	for (int i = 1; i <= n; i++) {
		vector<array<int, 3>> a;
		a = G[i];
		sort(a.begin(), a.end());
		for (auto t : a) {
			int w = t[0], u = t[1], x = t[2];
			if (x && !p[x]) {
				p[x] = 1;
				int uu = find(find, i), vv = find(find, u);
				if (uu != vv) {
					ans += w;
					fa[uu] = vv;
//					cout << -1 << "\n";
					if (a[i][x]) w -= c[x][i];
					else a[i][x] = 1;
					if (a[u][x]) w -= c[x][u];
					else a[u][x] = 1;
//					cout << i << " " << u << " " << x << " " << w << "\n";
					break;
				}
			} else if (x && p[x]) {
				w -= q[x];
				int uu = find(find, i), vv = find(find, u);
				if (uu != vv) {
					ans += w;
					fa[uu] = vv;
//					cout << 1 << "\n";
					if (a[i][x]) w -= c[x][i];
					else a[i][x] = 1;
					if (a[u][x]) w -= c[x][u];
					else a[u][x] = 1;
//					cout << i << " " << u << " " << x << " " << w << "\n";
					break;
				}
			} else {
				int uu = find(find, i), vv = find(find, u);
				if (uu != vv) {
					ans += w;
					fa[uu] = vv;
//					cout << i << " " << u << " " << w << "\n";
					break;
				}
			}
		}
	}
	cout << ans;
	return ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 2
1 4 100
1 3 100
1 2 100
2 3 1
1 1 1 1 1
1 1 1 1 2
*/
