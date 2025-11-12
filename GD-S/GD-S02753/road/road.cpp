#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 7, K = 17, M = 2e7 + 7;

int n, m, k;
int a[K][N];
struct Edge{
	int u, v, w;
}edge[M];

int fa[N];
void init() { for (int i = 0; i < N; ++i) fa[i] = i;}
int _find(int x) { return x == fa[x] ? x : fa[x] = _find(fa[x]);}
void merge(int x, int y) { fa[_find(x)] = _find(y); }

int cnt, ans;
bool cmp(Edge x, Edge y) { return x.w < y.w; }
void MST() {
	init();
	sort(edge+1, edge+1+m, cmp);
	for (int i = 1; i <= m; ++i) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if (_find(u) == _find(v)) continue;
		cnt++, ans += w;
		merge(u, v);
		if (cnt == n-1) break;
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	if (k == 0) {// 16 pts
		MST();
		cout << ans;
		return 0;
	}
	//36 pts
	for (int i = 1; i <= k; ++i) {
		int x; cin >> x;
		for (int j = 1; j <= n; ++j) cin >> a[i][j];
		for (int j = 1; j <= n; ++j) {
			for (int k = j+1; k <= n; ++k) {
				edge[++m] = {j, k, a[i][j] + a[i][k]};
			}
		}
	}
	MST();
	cout << ans;
	return 0;
}
