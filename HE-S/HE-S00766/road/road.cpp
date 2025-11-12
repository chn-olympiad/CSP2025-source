#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e6 + 10;
struct node {
	int st, en;
	ll w;
	bool operator < (const node & rhs) const {
		return w < rhs.w;
	}
} edge[M];
ll ans;
int fa[M], n, cnt, k, m;

int find(int x) {
	if (x == fa[x]) return fa[x];
	fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> edge[i].st >> edge[i].en >> edge[i].w;
	}
	for (int i = 1; i <= n; i ++) fa[i] = i;
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= m; i ++) {
		int u = edge[i].st, v = edge[i].en;
		if (find(u) == find(v)) continue ;
		ans += edge[i].w;
		fa[find(u)] = find(v);
//		cout << "u = " << u << " v = " << v << " w = " << edge[i].w << "\n";
		cnt ++;
		if (cnt == n - 1) break ;
	}
	cout << ans << "\n";
	
	return 0;
}
