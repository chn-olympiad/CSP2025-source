#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e7 + 7, M = 17, K = 1e3 + 7;;

struct node {
	int u, v, w;
} e[N];

int fa[10007], a[M][K];

int n, m, k, sum = 0;

inline int find(int x) {
	if (fa[x] == x)
		return fa[x];
	
	return fa[x] = find(fa[x]);
}

inline bool cmp(node a, node b) {
	return a.w < b.w;
}

inline void kruskal() {
	int cnt = 0;	
	sort(e + 1, e + 1 + m, cmp);
	
	for (int i = 1; i <= m; ++i) {
		int uu = find(e[i].u), vv = find(e[i].v);
		
		if (uu == vv)
			continue;
		
		fa[vv] = uu;
		sum += e[i].w;
		++cnt;
		
		if (cnt == n - 1)
			break;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	
	if (k == 0) {
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
			
		for(int i = 1; i <= m; ++i) {
			scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
			
		}
		
		for (int i = 1, c, a; i <= k; ++i) {
			cin >> c;
			
			for (int j = 1; j <= n; ++j)
				cin >> a;
		}
		
		kruskal();
		printf("%lld", sum);
		return 0;
	}
	
	int mm = m;
	for (int i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	
	for (int i = 1, c; i <= k; ++i) {
		cin >> c;
		
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= k; ++i) {
		for (int j = i; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				e[++mm].u = j, e[mm].v = k;
				e[mm].w = a[i][j] + a[i][k];
				e[++m].u = k;
				e[mm].v = j;
				e[mm].w = a[i][j] + a[i][k];
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	
	int cnt = 0;	
	sort(e + 1, e + 1 + mm, cmp);
	
	for (int i = 1; i <= mm; ++i) {
		int uu = find(e[i].u), vv = find(e[i].v);
		
		if (uu == vv)
			continue;
		
		fa[vv] = uu;
		sum += e[i].w;
		++cnt;
		
		if (cnt == n - 1)
			break;
	}
	
	printf("%lld", sum);
	return 0;
}

/*
4 4 1 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
0 1 8 2 4 
100 1 3 2 4 

*/
