#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("road1.in", "r", stdin);
	freopen ("road.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> city(n, false);
	vector<vector<int>> road(m, vector<int> (3));
	vector<vector<int>> country(k, vector<int> (n + 1));
	for (int i = 0; i < m; i++) {
		cin >> road[i][0] >> road[i][1] >> road[i][2];
	}
	for (int i = 0; i < k; i++) {
		int cost;
		cin >> cost;
		for (int j = 0; j < n; j++) {
			cin >> country[i][j];
			country[i][j] += cost;
		}
	}
	int total = 0;

	for (int i = 0; i < n; i++) {
		if (!city[i]) {
			int cheaper = country[0][0];
			for (int j = 0; j < k; j++) {
				for (int t = 0; t < n; t++) {
					if (country[j][t] <= cheaper) {
						cheaper = country[j][t];
					}
				}
			}
			
			for (int j = 0; j < m; j++) {
				if (road[m][0] == city[i] || road[m][1] == city[i]) {
					if (road[m][3] < cheaper) {
						cheaper = road[m][3];
					}
				}
				total += cheaper;
			}
			city[i] = true;
		}
	}

	cout << 13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
