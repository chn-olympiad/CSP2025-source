#include<bits/stdc++.h>
#define int64 long long
using namespace std;
const int N = (int)1e4 + 20;
const int M = (int)2e6 + 5;
const int INF = (int)1e9;

struct node {
	int u, v, w;
	
	bool operator<(const node &other) const {
		return w < other.w;
	}
} roads[N * N];

int n, m, k, cnt, num;
int fa[M], rebuild[M];
int64 ans;
map<int, bool> vis;

int find(int x) {
	if (fa[x] == x)	return x;
	else	return  fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &roads[i].u, &roads[i].v, &roads[i].w);
	}
	
	cnt = m;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &rebuild[n + i]);
		for(int w, j = 1; j <= n; j++) {
			scanf("%d", &w);
			++cnt;
			roads[cnt].u = n + i;
			roads[cnt].v = j;
			roads[cnt].w = w + rebuild[n + i];
		}
	} 
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		vis[i] = true;
	}
	
	sort(roads + 1, roads + 1 + cnt);
	
//	for (int i = 1; i <= cnt; i++)	printf("%d ", roads[i].w);
	
//	for (int i = 1; i <= cnt; i++) {
//		int x = roads[i].u, y = roads[i].v;
//		x = find(x), y = find(y);
//		if (x != y) {
//			if (!vis[roads[i].u]) {
//				roads[i].w += rebuild[roads[i].u], vis[roads[i].u] = true;
//				printf("%d: %dyuan\n", roads[i].u, rebuild[roads[i].u]);
//			}
//		}
//	}
	
//	sort(roads + 1, roads + 1 + cnt);
	
//	for(int i = 1; i <= cnt; i++)	printf("%d ", roads[i].w);
	
	for (int i = 1; i <= cnt; i++) {
		int x = roads[i].u, y = roads[i].v;
		x = find(x), y = find(y);
		if (x != y) {
			fa[y] = x;
			num++;
			if (!vis[roads[i].u]){
				n++;
//				printf("\npick: %d and then %d points\n", roads[i].u, n);
				vis[roads[i].u] = true;
				ans = ans + 1ll * roads[i].w;
			} else {
				ans = ans + 1ll * (roads[i].w - rebuild[roads[i].u]);
			}
			if (num == n - 1) break;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
/*
用不用开 int64？ 

在城市化改造完第j(1≤j≤k)个乡镇
后，可以在这个乡镇与原来的n座城市间建造若干条道路

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
