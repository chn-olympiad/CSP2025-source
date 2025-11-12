#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > a[100005];
int r[15], ans = INT_MAX;
bool f[100005];
void dfs(int x, int s, int sum) {
	if (sum >= ans) {
		return ;
	}
	if (s == n) {
		ans = sum;
		return ;
	}
	for (int i = 0; i < a[x].size(); i++) {
		if (f[a[x][i].first]) {
			continue;
		}
		f[a[x][i].first] = 1;
		if (a[x][i].first <= n) {
			dfs(a[x][i].first, s + 1, sum + a[x][i].second);
		}
		else {
			dfs(a[x][i].first, s, sum + r[a[x][i].first - n] + a[x][i].second);
		}
		f[a[x][i].first] = 0;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int v, u, c;
		scanf("%d %d %d", &v, &u, &c);
		a[u].push_back({v, c});
		a[v].push_back({u, c});
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &r[i]);
		for (int j = 1; j <= n; j++) {
			int v;
			scanf("%d", &v);
			a[j].push_back({i + m, v});
			a[i + m].push_back({j, v});
		}
	}
	f[1] = 1;
	dfs(1, 1, 0);
	printf("%d", ans);
	return 0;
}
