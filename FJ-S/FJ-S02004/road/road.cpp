#include <bits/stdc++.h>
using i64 = long long;
const int N = 1e4 + 10, M = 1e6 + 10;
const i64 linf = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
struct node {
	int u, v;
	i64 w;
} a[M << 1];
int fa[N];
int find(int x) {
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}
bool cmp(node a, node b) {
	return a.w < b.w;
}
int c[15], f[15][N];
i64 ans, sum;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++) {
		std::cin >> a[i].u >> a[i].v >> a[i].w;
	}
	
	for(int i = 1; i <= k; i++) {
		std::cin >> c[i];
		for(int j = 1; j <= n; j++) {
			std::cin >> f[i][j];
		}
	}
	
	if(!k) {
		std::sort(a + 1, a + m + 1, cmp);
		
		for(int i = 1; i <= n; i++) fa[i] = i; 
		for(int i = 1; i <= m; i++) {
			int x = find(a[i].u), y = find(a[i].v);
			if(x == y) continue;
			fa[x] = y;
			ans += a[i].w;
		}
		
		std::cout << ans << "\n";
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			i64 ret = linf;
			for(int x = 1; x <= k; x++) {
				ret = std::min(ret, 1LL * c[x] + f[x][i] + f[x][j]);
			}
			a[++m] = {i, j, ret};
		}
	}
	std::sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i; 
	for(int i = 1; i <= m; i++) {
		int x = find(a[i].u), y = find(a[i].v);
		if(x == y) continue;
		fa[x] = y;
		ans += a[i].w;
	}
	
	std::cout << ans << "\n";
		
	return 0;
}
