#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, m, k, fa[N], vis[15], cnt;
ll ans, c[15], a[15][10005];
struct node {
	int u, v, w, c;
	void read (){
		cin >> u >> v >> w;
	}
}g[N];

int find (int f){
	if (fa[f] == f) return f;
	return fa[f] = find(fa[f]);
}

void merge (int x, int y){
	fa[y] = fa[x];
}

bool cmp (node x, node y){
	return x.w < y.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) g[i].read();
	int p = m + 1;
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	sort (g + 1, g + n + 1, cmp);
	for (int i = 1; i <= m; i++){
		int u = g[i].u, v = g[i].v, tp = -1;
		ll minn = g[i].w;
		if (find(fa[u]) != find(fa[v])){
			if (cnt == n - 2){
				for (int x = 1; x <= n; x++){
					for (int y = x + 1; y <= n; y++){
						if (find(fa[x]) != find(fa[y]) && ((x != u || y != v) || (x != v || y != u))){
							for (int j = 1; j <= k; j++){
								if (vis[j]) minn = min(minn, a[j][x] + a[j][y]);
								else {
									if (minn > a[j][x] + a[j][y] + c[j]){
										minn = a[j][x] + a[j][y] + c[j];
										tp = j;
									}
								}
							}
						}
					}
				}
			}
			for (int j = 1; j <= k; j++){
				if (vis[j]) minn = min(minn, a[j][u] + a[j][v]);
				else {
					if (minn > a[j][u] + a[j][v] + c[j]){
						minn = a[j][u] + a[j][v] + c[j];
						tp = j;
					}
				}
			}
			if (tp > 0) vis[tp] = 1;
			ans += minn;
			merge(u, v);
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
