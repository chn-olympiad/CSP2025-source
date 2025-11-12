#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
using ll = long long;

const int N = 1e4 + 3;
const int M = 3e6 + 3;

struct Edge {
	int v, w;
};
struct Edge2 {
	int u, v, w;
} edges[M];

int n, m, k;
vector<Edge> e[N];
int c[11];
int ca[11][N];
vector<int> cList;

ll ans;

int fa[N];
int Find(int u) {
	if (fa[u] == u) {
		return u;
	}
	return fa[u] = Find(fa[u]);
}

void SCS() {
	sort(edges + 1, edges + m + 1, [](Edge2 u, Edge2 v) {
		return u.w < v.w;
	});
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		int fu = Find(u), fv = Find(v);
		if (fu == fv) continue;
		fa[v] = fu;
		ans += (ll)w;
		cnt++;
		if (cnt >= n - 1) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[u].push_back(Edge{v, w});
		e[v].push_back(Edge{u, w});
		edges[i] = Edge2{u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> ca[i][j];
		}
	}
	SCS();
	cout << ans;
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
