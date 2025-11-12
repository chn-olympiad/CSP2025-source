#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
const int MAXM = 1e1 + 5;
int a[MAXN], ans[MAXM][MAXM];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, target = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
		target = a[1];
	}
	int k = n * m;
	bool flag = true;
	sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n; ++i) {
		if (flag) {
			for (int j = 1; j <= m; ++j) {
				ans[i][j] = a[k];
				k--;
			}	
			flag = false;
		}
		else {
			for (int j = m; j >= 1; --j) {
				ans[i][j] = a[k];
				k--;
			}	
			flag = true;
		}
		
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (ans[i][j] == target) {
				cout << i << ' ' << j;
				break;
			}
//			cout << ans[i][j] << ' ';
		}
//		cout << '\n';
	}
	return 0;
} 
