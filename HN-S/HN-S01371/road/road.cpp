#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, c[15], a[15][N], fa[N], vis[15], ans = 0;
struct Edge {
	int u, v, w;
	bool operator < (Edge B) const {
		return w < B.w;
	}
} e[M]; 
struct Node {
	int to, val;
};
vector<Node> vt[N + M + 15];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

bool uniSet(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	fa[x] = y;
	return true;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i =1 ; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	sort(e + 1, e + m + 1);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (uniSet(e[i].u, e[i].v)) {
			e1[i] = e[i];
			cnt++;
			ans += e[i].w;
		}
		if (cnt == n - 1) break;
	}
	cout << ans << endl;
	return 0;
}

