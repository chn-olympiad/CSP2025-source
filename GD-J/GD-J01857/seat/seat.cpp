#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	vector<int> a(n * m);
	for (int i = 0; i < n * m; i++) cin >> a[i];
	int x = a[0];
	sort(a.begin(), a.end(), greater<int>());
	
	vector<vector<int>> mat(n, vector<int>(m));
	for (int j = 0, k = 0; j < m; j++) {
		if (j & 1) {
			for (int i = n - 1; i >= 0; i--) mat[i][j] = a[k++];
		}
		else {
			for (int i = 0; i < n; i++) mat[i][j] = a[k++];
		}
	}
	
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < m; j++)
	        if (mat[i][j] == x) {
	        	cout << j + 1 << ' ' << i + 1 << '\n';
	        	break;
			}

	return 0;
}
