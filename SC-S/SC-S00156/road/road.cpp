#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
const int N = 10005, M = 1000005;
// long long
/*
O(n * logn * 2^k) ~= 1000 * 1e4 * 10
复杂度卡的有点死a ? 
可能要卡常了 

road3跑了1.071秒，有点爆炸
算了不必理会开T3 4:00 !!! 
*/
struct edge{int u, v, w;};
edge edges[M];
edge Treg[N * 12]; int tcnt = 0;
bool cmp(edge x, edge y) {return x.w < y.w;}
int fa[N + 15];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int trueans = 0;
int c[15], a[15][N];
inline int read() {
	char c = getchar();
	int s = 0;
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	return s;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
//	scanf("%lld%lld%lld", &n, &m, &k);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
//		scanf("%lld%lld%lld", &u, &v, &w);
		u = read(); v = read(); w = read();
		edges[i] = edge{u, v, w};
	} 
	for(int i = 1; i <= n; ++i) fa[i] = i;
	std::sort(edges + 1, edges + m + 1, cmp);
	for(int i = 1; i <= m; ++i) {
		int fu = find(edges[i].u), fv = find(edges[i].v);
		if(fu == fv) continue;
		Treg[++tcnt] = edges[i];
		trueans += edges[i].w; 
		fa[fu] = fv;
	}
//	printf("\n");
//	for(int i = 1; i <= tcnt; ++i) {
//		printf("%lld %lld %lld\n", Treg[i].u, Treg[i].v, Treg[i].w);
//	}
	for(int i = 1; i <= k; ++i) {
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; ++j) {
			scanf("%lld", &a[i][j]);
		}
	}
//	printf("Trueans org = %lld\n", trueans);
	int ans, cnt;
	for(int i = 1; i < (1 << k); ++i) {
		for(int j = 1; j <= n + k; ++j) fa[j] = j;
		ans = 0; cnt = tcnt;
		for(int j = 1; j <= tcnt; ++j) edges[j] = Treg[j];
		for(int j = 1; j <= k; ++j) {
			if(i & (1 << (j - 1))) {
				ans += c[j];
				for(int l = 1; l <= n; ++l) {
					edges[++cnt] = edge{n + j, l, a[j][l]};
				}
			}
		} 
		std::sort(edges + 1, edges + cnt + 1, cmp);
		int Tim = 0;
		for(int i = 1; i <= cnt; ++i) {
			if(ans >= trueans) break;
			if(Tim > n + k) break;
			int fu = find(edges[i].u), fv = find(edges[i].v);
			if(fu == fv) continue;
			++Tim; fa[fu] = fv;
			ans += edges[i].w;
		} trueans = std::min(trueans, ans); 
	} 
	printf("%lld", trueans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/