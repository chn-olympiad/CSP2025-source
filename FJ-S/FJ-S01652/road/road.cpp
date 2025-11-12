#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n = 1e4 + 5;
const int max_m = 1e7 + 5;

int n, m, k, ans = 0;
int c[max_n], f[max_n];
int a[max_n][max_n];

struct Node {
	int u, v, nxt, w;
}e[max_m];

int h[max_n], idx;

inline void add(int u, int v, int w) {
	e[++idx] = {u, v, h[u], w};
	h[u] = idx;
}

int cmp(Node a, Node b) {
	return a.w < b.w;
}

inline int find(int x) {
	if (f[x] != x) {
		f[x] = find(f[x]);
	}
	return f[x];
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for (int i = 1; i <= max_n; i++)
		f[i] = i;
	          
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		add(u, v, w);
		add(u, v, w); 
	}
	
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			int w;
			scanf("%lld", &w);
			add(i * n + 1, j, c[i]);
			add(j, i * n + 1, c[i] + w);
		} 
	}
	
	sort(e + 1, e + idx + 1, cmp);
	
	for (int i = 1; i <= idx; i++) {
		int u = e[i].u, v = e[i].v;
		if (find(u) != find(v)) {
			f[find(u)] = f[find(v)];
			ans += e[i].w;
			
			bool flag = true;
			
			for (int i = 2; i <= n; i++) {
				if (find(i) != find(i - 1)) {
					flag = false; 
					break;
				}
			}
			
			if (flag)
				break;
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}