#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[110];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a[0] = a[1];
	sort (a + 1, a + n * m + 1, cmp);
//	for (int i = 1; i <= n * m; i++) cout << a[i] << " ";
//	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[(i - 1) * n + j] == a[0]) {
//				cout << (i - 1) * n + j << endl;
				if (i & 1) {
					cout << i << " " << j << endl;
				} else {
					cout << i << " " << m - j + 1 << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
