#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i)
using namespace std;

//force
const int N = 1e4 + 5, K = 10 + 5, M = 1e6 + 5;

struct Edge {
	int u, v, w;
} edges[M + K * M];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
int n, m, k1, tot, c[N], a[K][N], fa[N + K], ans;
int find(int x) {
	if(x == fa[x]) return fa[x];
	else return fa[x] = find(fa[x]);
}
void join(int x, int y, int w) {
	int f1 = find(x), f2 = find(y);
	fa[f1] = f2;
	ans += w;
}
void kruskal() {
	set < int > s;
	sort(edges + 1, edges + 1 + m + k1 * n, cmp);
	inc(i, 1, n) fa[i] = i;
	inc(i, 10001, 10000 + k1) fa[i] = i;
	
	
	int cnt = 0;
	inc(i, 1, m) {
		if(s.size() == n) break;
		if(find(edges[i].u) != find(edges[i].v)) {
			++cnt;
			//cout << "+" << edges[i].w << '\n';
			join(edges[i].u, edges[i].v, edges[i].w);
			if(edges[i].u <= n) s.insert(edges[i].u);
			if(edges[i].v <= n) s.insert(edges[i].v);
		}
	}
	
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> k1;
	inc(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		edges[++tot] = (Edge){u, v, w};
		//cout << edges[tot].u << " " << edges[tot].v << " " << edges[tot].w << '\n';
	}
	inc(i, 1, k1) {
		cin >> c[i];
		inc(j, 1, n) {
			cin >> a[i][j];
		}
	}
	inc(i, 1, k1) {
		inc(j, 1, n) {
			edges[++tot] = (Edge){10000 + i, j, a[i][j] + c[i]};
			//cout << edges[tot].u << " " << edges[tot].v << " " << edges[tot].w << '\n';
		}
	}
	kruskal();
	cout << ans << '\n';
	return 0;
} 
