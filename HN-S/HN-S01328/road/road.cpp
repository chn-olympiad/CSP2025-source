#include <bits/stdc++.h>
using namespace std;
long long ans, fa[10010];
int siz;
struct node {
	int u, v, w;
} edge[3000100];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int find(int x) {
	if (fa[x] == x) return x;
	return find(fa[x]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

void p() {
	for (int i = 1; i <= siz; i ++) {
		if (find(edge[i].u) == find(edge[i].v)) continue;
		ans += edge[i].w;
		merge(edge[i].u, edge[i].v);
	}
}

int main() {
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	} 
	int cnt = m;
	for (int i = 1; i <= k; i ++) {
		int tmp;
		cin >> tmp;
		for (int j = 1; j <= n; j ++) {
			int x;
			cin >> x;
			edge[++ cnt] = {i, j, x};
		}
	}
	siz = cnt;
	sort(edge + 1, edge + 1 + siz, cmp);
	for (int i = 1; i <= siz; i ++) {
		cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;
	} 
	for (int i = 1; i <= n; i ++) fa[i] = i;
	p();
	cout << ans;
} 
