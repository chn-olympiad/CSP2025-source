#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R;
	cin >> n >> m;
	vector<int> a(n * m);
	for(int i = 0; i < n * m; ++i) {
		cin >> a[i];
	}
	R = a[0];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	vector<vector<int>> b(n, vector<int> (m));
	int id = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			b[i][j] = a[id++];
		}
		if(i & 1) reverse(b[i].begin(), b[i].end());
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(b[i][j] == R) {
				cout << i + 1 << ' ' << j + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}
