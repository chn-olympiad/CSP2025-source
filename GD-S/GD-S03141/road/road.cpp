#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
struct edge{
	int v;
	int w;
	int u;
};
bool cmp (edge a, edge b) {
	return a.w < b.w;
}
int fa[maxn];
int find(int u) {
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	fa[u] = v;
	return ; 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++) fa[i] = i;
	if(k == 0) {
		vector<edge> edges;
		for(int i = 0; i < m; i++) {
			edge e;
			cin >> e.u >> e.v >> e.w;
			edges.push_back(e);
		}
		for(int i = 0; i < k; i++) {
			int c;
			cin >> c;
			for(int i = 0; i < n; i++) {
				int w;
				cin >> w;
			}
		}
		
		sort(edges.begin(), edges.end(), cmp); 
		long long ans = 0;
		
		for(int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if(find(e.u) != find(e.v)) {
				merge(e.u, e.v);	
				ans += e.w;
			}
		}
		cout << ans << "\n";
	}
	else cout << 0 << "\n";
	return 0;
}
