#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct Edge {
	int u, v, w, id;
} e[M];

int fa[N], n, m, k;

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[x] = fa[y];
}

ll kruskal() {
	sort(e + 1, e + 1 + m, cmp);
	
	for (int i = 1; i <= n; i++) fa[i] = i;
	
	int nedge = 0;
	ll s = 0;
	for (int i = 1; i <= m; i++) {
		int r1 = find(e[i].u), r2 = find(e[i].v);
		if (r1 == r2) continue;
		merge(r1, r2);
		
		nedge++;
		s += e[i].w;
		
		if (nedge == n - 1) return s;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].id = i;
	}
	
	for (int j = 1; j <= k; j++) {
		int c;
		cin >> c; 
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
		}
	}
	
	cout << kruskal();
	
	return 0;
}

/*
4 4 0
1 2 100
2 3 20
3 4 30
4 1 30

*/
