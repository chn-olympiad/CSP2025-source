#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1, x = 0, y = 0;
	cin >> n >> m;
	vector<int> a(n * m, 0);
	vector<vector<int>> sq(n, vector<int>(m, 0));
	for (auto &x : a) cin >> x;
	a1 = a[0];
	sort(a.begin(), a.end());
	for (int i = n * m - 1; i >= 0; i--) {
		sq[x][y] = a[i];
		x += (y % 2? -1 : 1);
		if (x == n || x == -1) {
			y++;
			x += (x == n? -1 : 1);
		}
	} for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sq[i][j] == a1) {
				cout << i + 1 << " " << j + 1;
				return 0;
			}
		} 
	}
}
