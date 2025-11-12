#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[20], a[20][10010], f[10010];
vector<pair<int, int>> edge[10010];
array<int, 3> G[1000010];

int findset(int x){
	return (f[x] == x) ? x : (f[x] = findset(f[x]));
}

inline void kruskal(){
	for (int i = 1; i <= n; i++)
		f[i] = i;
	sort(G + 1, G + m + 1);
	long long ans = 0;
	for (int i = 1; i <= m; i++){
		int d = G[i][0], x = G[i][1], y = G[i][2];
		int fx = findset(f[x]), fy = findset(f[y]);
		if (fx != fy)
			f[fy] = fx, ans += d;
	}
	printf ("%lld\n", ans);
}

int main(){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++){
		int x, y, z;
		scanf ("%d%d%d", &x, &y, &z);
		edge[x].push_back({y, z});
		edge[y].push_back({x, z});
		if (!k)
			G[i] = {z, x, y};
	}
	if (!k){
		kruskal();
		return 0;
	}
	for (int i = 1; i <= k; i++){
		scanf ("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf ("%d", &a[i][j]);
	}
	
	return 0;
}
