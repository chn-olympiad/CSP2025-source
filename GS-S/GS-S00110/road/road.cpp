#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    freopen("./road3.in", "r", stdin);
    freopen("./road3.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long>> roads(m, vector<long long>(3, 0));
    vector<vector<long long>> road_costs(n + 1, vector<long long>(n + 1, 1000000001));
    for (int i = 0; i < m; ++i) {
    	long long a, b, c;
		cin >> a >> b >> c;
		road_costs[a][b] = c;
		road_costs[b][a] = c;
	}
	vector<vector<long long>> villages(k, vector<long long>(n + 1, 0));
	for (int j = 0; j < k; ++j) {
		for (int i = 0; i < n + 1; ++i) {
			cin >> villages[j][i];
		}
	}
	for (int t = 0; t < k; ++t) {
		for (int i = 1; i < n + 1; ++i)	{
			for (int j = i + 1; j < n + 1; ++j) {
				road_costs[i][j] = min(road_costs[i][j], villages[t][i] + villages[t][j] + villages[t][0]);
			}
		}	
	}
	priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> final_roads;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = i + 1; j < n + 1; ++j) {
			if (road_costs[i][j] < 1000000001) {
				vector<long long> cost = {road_costs[i][j], i, j};
				final_roads.push(cost);
			}
		}
	}
	long long final_cost = 0;
	vector<bool> visited(n + 1, false);
	while (!final_roads.empty()) {
		int start = final_roads.top()[1];
		int end = final_roads.top()[2];
		long long sub_cost = final_roads.top()[0]; 
		if (!visited[start] || !visited[end]) {
			visited[start] = true;
			visited[end] = true;
			final_cost += sub_cost;
		}
		final_roads.pop();
	}
	cout << final_cost << endl;
    return 0;
}
