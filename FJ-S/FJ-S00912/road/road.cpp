#include <iostream>
using namespace std;

int n, m, k;
int city_roads[10001][10001] = {0};
int town_roads[11][10001] = {0};

int ans = INT_MAX;
bool visited[10001] = {false};

void dfs(int now_city, int now_weight) {
	if(now_city > n) {
		ans = min(ans, now_weight);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!visited[i] && city_roads[now_city][i]) {
			visited[i] = true;
			dfs(i, now_weight + city_roads[now_city][i]);
			visited[i] = false;
		}
	}
	
	dfs(now_city + 1, now_weight);
}

int main() {
	freopen("road.out", "w", stdout);
	freopen("road.in", "r", stdin);
	
	cin >> n >> m >> k;
	
	int u, v, w;
	for(int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		city_roads[u][v] = w;
		city_roads[v][u] = w;
	}
	
	for(int i = 1; i <= k; i++) {
		cin >> town_roads[i][0]; // build money 
		for(int j = 1; j <= n; j++) {
			cin >> town_roads[i][j];
		}
	}
	
	dfs(1, 0);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(!city_roads[i][j]) {
				city_roads[i][j] = 1;
				city_roads[j][i] = 1;
				
				int now = INT_MAX;
				for(int l = 1; l <= k; l++) {
					int sum = town_roads[l][0] + town_roads[l][i] + town_roads[l][j];
					now = min(now, sum);
				}
				ans += now;
			}
		}
	}
	
	cout << ans;
	return 0;
}
