#include <iostream> 
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int rd[m][3], cost[m];
	for (int i = 0; i < m; i++) {
		cin >> rd[i][0] >> rd[i][1] >> rd[i][2];
		cost[i] = rd[i][2];
	}
	
	int ans = 0;
	sort(cost, cost+k);
	for (int i = 0; i < n; i++) ans += cost[i];
	cout << ans/2+1;
	return 0;
}
