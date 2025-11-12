#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

struct Edge {
	int u, v, w;
	bool operator<(const Edge &rhs) const {
		return w < rhs.w;
	}
};

vector<Edge> edges;
int fa[10010];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		fa[x] = y;
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
//	if (!k) {
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			edges.pb({u, v, w});
		}
		sort(edges.begin(), edges.end());
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
		}
		int sum = 0;
		for (int i = 0, cnt = 0; i < m; ++i) {
			if (find(edges[i].u) != find(edges[i].v)) {
				merge(edges[i].u, edges[i].v);
				sum += edges[i].w;
				++cnt;
				if (cnt == n - 1) {
					break;
				}
			}
		}
		cout << sum << endl;
//		return 0;
//	}
	return 0;
}

