#include <bits/stdc++.h>
#define int long long
using namespace std;
#define pii pair<int, int>
#define a4i array<int, 4>

const int MAXN = 10005;
const int MAXK = 15;

int n, m, k;
vector<pii> g[MAXN];
int c[MAXK];
int a[MAXK][MAXN];
bool h[MAXK];
bool o[MAXK][MAXN];
bool vis[MAXN];
int p;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	priority_queue<a4i, vector<a4i>, greater<a4i>> q;
	vis[1] = true;
	p = 1;
	for (pii t: g[1]) {
		int v = t.first;
		int w = t.second;
		q.push({w, 1, v, -1});
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 2; j <= n; j++) {
			q.push({c[i] + a[i][1] + a[i][j], 1, j, i});
		}
	}
	int cst = 0;
	while (!q.empty()) {
		a4i t = q.top();
		q.pop();
		int w = t[0];
		int u = t[1];
		int v = t[2];
		int b = t[3];
		if (vis[u] && vis[v]) continue;
		if (vis[v]) swap(u, v);
        vis[u] = true;
		vis[v] = true;
		p++;
        for (pii d: g[v]) {
            int dv = d.first;
            int dw = d.second;
            q.push({dw, v, dv, -1});
        }
		cst += w;
		if (b != -1 && !h[b]) {
			h[b] = true;
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) continue;
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					int r = 0;
					if (!o[b][i]) r += a[b][i];
					if (!o[b][j]) r += a[b][j];
					q.push({r, i, j, b});
				}
			}
		}
		if (p >= n) {
			cout << cst << endl;
			return 0;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (u == j) continue;
				int r = 0;
				if (!h[i]) r += c[i];
				if (!o[i][u]) r += a[i][u];
				if (!o[i][j]) r += a[i][j];
				q.push({r, u, j, i});
			}
		}
		for (pii d: g[u]) {
			int v = d.first;
			int w = d.second;
			q.push({w, u, v, -1});
		}
	}
	cout << cst << endl;
	return 0;
}
