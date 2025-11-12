#include <stdio.h>
#include <algorithm>
struct ROAD {
	int u, v, w;
	int dependUpgrade;
};
int n, m, k, f[11451], upgraded[114], upgCost[114];
ROAD roads[1145141];
bool cmp(ROAD a, ROAD b) {
	if(upgCost[a.dependUpgrade] == upgCost[b.dependUpgrade]) {
		return a.w < b.w;
	}
	return upgCost[a.dependUpgrade] < upgCost[b.dependUpgrade];
}
int find(int x) {
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void merge(int x, int y) {
	f[find(x)] = find(y);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	int i, rdcnt = 0;
	for(i = 1; i <= n + k; i += 1) f[i] = i;
	for(i = 1; i <= m; i += 1) {
		scanf("%d %d %d", &roads[i].u, &roads[i].v, &roads[i].w);
	}
	rdcnt = m;
	for(i = 1; i <= k; i += 1) {
		int rdCost;
		scanf("%d", &upgCost[i]);
		int j;
		for(j = 1; j <= n; j += 1) {
			scanf("%d", &rdCost);
			rdcnt += 1;
			roads[rdcnt].u = n + i;
			roads[rdcnt].v = j;
			roads[rdcnt].w = rdCost;
			roads[rdcnt].dependUpgrade = i;
		}
	}
	std::sort(roads + 1, roads + rdcnt + 1, cmp);
	long long cost = 0;
	upgraded[0] = 1;
	for(i = 1; i < rdcnt; i += 1) {
		if(find(roads[i].u) != find(roads[i].v)) {
			merge(roads[i].u, roads[i].v);
			cost += roads[i].w;
			if(upgraded[roads[i].dependUpgrade] == 0) {
				cost += upgCost[roads[i].dependUpgrade];
				upgraded[roads[i].dependUpgrade] = 1;
			}
		}
		int j, flg = 0, grand = find(1);
		for(j = 2; j <= n; j += 1) {
			if(find(j) != grand) {
				flg = 1;
				break;
			}
		}
		if(flg == 0) break;
	}
	printf("%lld", cost);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
