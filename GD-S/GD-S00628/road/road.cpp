#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 1;
const int INF = INT_MAX;
typedef long long ll;
int n, m, k, vis[maxn], d[maxn], a[maxn][maxn], c[maxn];
struct edge{
	int v, w;
};
vector<edge> g[maxn];
void di(int s) {
	priority_queue<pair<int, int>> q;
	fill(d, d + maxn, INF);
	memset(vis, 0, sizeof(vis));
	q.push({0, s});
	d[s] = 0;
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		int u = t.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e : g[u]) {
			int v = e.v, w = e.w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({-d[v], v});
			}
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	di(1);
	for (int i = 1; i <= n; i++) {
		ans += d[i];
	}
	cout << ans;
	return 0; 
}
