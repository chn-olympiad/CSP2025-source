#include <bits/stdc++.h>
using namespace std;
struct Road {
	int from_city;
	int to_city;
	int rb_cost;
} roads[100010];
int ctss[11][10004];
vector<vector<bool> >b;
vector<vector<int> > cities;
int n, m, k, ans = 0;

void iptcs_() {
	int a, b;
	for (int i = 0; i < m; i++) {
		a = max(roads[i].from_city, roads[i].to_city);
		b = min(roads[i].from_city, roads[i].to_city);
		cities[a][b] = roads[i].rb_cost;
	}
	for (int i = n+1; i <= n+k; i++) {
		for (int j = 1; j <= n; j++) {
			cities[i][j] = ctss[i-n][j];
		}
		cities[i][n+1] = ctss[i-n][0];
	}
}

void dfs_(int x, int y) {
	for (int i = x; i < y; i++) {
		for (int j = y; j < n+k; j++) {
			if (!b[i][j]) {
				ans += cities[i][j];
				b[i][j] = 1;
				dfs_(i, j);
				b[i][j] = 0;
				//ans -= a[i][j];
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &roads[i].from_city, &roads[i].to_city, &roads[i].rb_cost);
	}
	memset(ctss, 0, sizeof(ctss));
	for (int i = 0; i < m; i++) {
		scanf("%d", &ctss[i][0]);
		for (int j = 1; j <= k; j++) {
			scanf("%d", &ctss[i][j]);
		}
	}
	iptcs_();
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			ans += cities[i][j];
		}
	}
	printf("%d", (ans+1)/2);
	//dfs_(1, 2);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
