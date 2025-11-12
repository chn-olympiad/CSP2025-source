#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, fa[10005], c[15], ww[10005][15];

vector <pair <int, int> > edge[100005]; 

struct node {
	int u, v, w;
}e[1000005];

bool cmp(node p, node q) {
	return p.w < q.w;
}

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++) {
			scanf("%d", &ww[i][j]);
		}
	} 
	if(k == 0) {
		sort(e + 1, e + m + 1, cmp);
		for(int i = 1; i <= n; i++) fa[i] = i;
		int ans = 0;
		for(int i = 1; i <= m; i++) {
			if(find(e[i].u) == find(e[i].v)) continue;
			int uu = find(e[i].u), vv = find(e[i].v);
			fa[uu] = vv;
			ans += e[i].w;
		}
		cout << ans;
		return 0;
	}
	
}
