#include <cstdio>
#include <vector>

using std::vector;

struct edge {
	int v, w;
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
		
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	vector<edge> e[n + 1];
	vector<int> c(k + 1);
	vector<vector<int>> a(k + 1, vector<int>(n + 1));
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
		
	}
	
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int ans = 0;
	printf("%d\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

