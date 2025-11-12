#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int b;
int c[105][105];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++ ) {
		cin >> a[i];
	}
	b = a[1];
	sort(a + 1, a + n * m + 1);
	int cnt = m * n + 1;
	for(int i = 1;i <= m;i ++ ) {
		if(i % 2 == 1) {
			for(int j = 1;j <= n;j ++ ) {
				c[j][i] = a[ -- cnt];
			}
		}
		else {
			for(int j = n;j >= 1;j -- ) {
				c[j][i] = a[ -- cnt];
			}
		}
	}
//	for(int i = 1;i <= n;i ++ ) {
//		for(int j = 1;j <= m;j ++ ) {
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1;i <= n;i ++ ) {
		for(int j = 1;j <= m;j ++ ) {
			if(c[i][j] == b) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
