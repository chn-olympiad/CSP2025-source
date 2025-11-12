#include<bits/stdc++.h>
using namespace std;
int n, m, k;
long long minc = INT_MAX;
map<pair<int, int>, int> city;
int cost[10 + 10];
bool open[10 + 10], vis[10000 + 10];
bool check() {
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i]) {
			return false;
		}
	}
	return true;
}
void dfs(int u, long long c) {
	if(check()) {
		minc = min(minc, c);
		return ;
	}
	for(int i = 1; i <= n + k; ++ i) {
		if(city[{u, i}] != 0 && !vis[i]) {
			vis[i] = true;
			dfs(i, c + city[{u, i}]);
			vis[i] = false;
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	minc *= INT_MAX;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		city[{u, v}] = w;
		city[{v, u}] = w;
	}
	for(int i = 1; i <= k; ++ i) {
		scanf("%d", &cost[i]);
		for(int j = 1; j <= n; ++ j) {
			int a;
			scanf("%d", &a);
			city[{n + i, j}] = cost[i] + a;
			city[{j, n + i}] = cost[i] + a;
		}
	}
	vis[1] = true;
	dfs(1, 0);
	printf("%lld", minc - 1);
	return 0;
}
