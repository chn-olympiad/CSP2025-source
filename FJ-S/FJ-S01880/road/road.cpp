#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 20, M = 3e6 + 5, C = 15;
int n, m, c;

int pri[C];
int pn[C][N];
bool open[C];
int opened;

int fa[N];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void unite(int x, int y) {
	auto fx = find(x), fy = find(y);
	if(fx != fy) fa[fx] = fy;
}

struct Edge {
	int u, v, w;
	const operator > (const Edge &b) const{
		return w > b.w;
	}
};

priority_queue<Edge, vector<Edge>, greater<Edge>> e;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> c;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push({u, v, w});
	}
	for (int i = 1; i <= c; i++) {
		cin >> pri[i];
		for (int j = 1; j <= n; j++) {
			cin >> pn[i][j];
			e.push({i + 10000, j, pn[i][j] + pri[i]});
		}
	}
	
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= c; i++) fa[i + 10000] = i + 10000;
	
	int cnt = 0;
	long long ans = 0;
	while (e.size()) {
		auto edge = e.top();
		e.pop();
		auto u = edge.u, v = edge.v, w = edge.w;
		
//		cout << endl << u << "->" << v << ": " << w << " ";
		if (find(u) != find(v)) {
			unite(u, v);
//			cout << "ok";
			cnt++;
			ans += w;
			if (u > 10000 && !open[u - 10000]) {
				open[u - 10000] = 1;
				opened++;
				for (int i = 1; i <= n; i++) {
					if (i == v) continue;
//					cout << endl << "    add " << u << "->" << i << ": " << pn[u - 10000][i];
					e.push({u, i, pn[u - 10000][i]});
				}
			}
		}
		
		if (cnt + 1 == n + opened) break;
	}
//	cout << endl;
	cout << ans;
}
