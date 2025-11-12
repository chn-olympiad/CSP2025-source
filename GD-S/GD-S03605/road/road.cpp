#include<bits/stdc++.h>
using namespace std;
int n, m, k;
long long ans;
struct Road{
	int ui, vi, wi;
} road[1000005];
bool cmp(Road a, Road b) {
	return a.wi < b.wi;
}
int pre[10005];
int find(int x) {
	if(pre[x] != x) {
		pre[x] = find(pre[x]); 
	}
	return pre[x];
}
struct cz{
	int cj, a[10005];
} CZ[11];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &road[i].ui, &road[i].vi, &road[i].wi);
	}
	for(int j = 1; j <= k; j ++) {
		scanf("%d", &CZ[j].cj);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &CZ[i].a[i]);
		}
	}
	sort(road + 1, road + 1 + m, cmp);
	for(int i = 1; i <= n; i ++) {
		pre[i] = i;
	}
	int cnt = n;
	for(int i = 1; i <= m; i ++) {
		if(cnt == 1) {
			printf("%lld", ans);
			return 0;
		}
		if(find(road[i].ui) != find(road[i].vi)) {
		  ans += road[i].wi;
		  cnt --;
		  pre[road[i].ui] = find(road[i].vi);
		}
	}
	return 0;
}
