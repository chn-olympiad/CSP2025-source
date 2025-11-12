#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[110];
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i];
	int t = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; --i)
		if (a[i] == t) {
			t = n * m - i + 1;
			break;
		}
	int i, j;
	bool f = 1;
	for (i = 1; i <= m; ++i) {
		if (f) {
			for (j = 1; j <= n; ++j) {
				if (--t == 0) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else {
			for (j = n; j >= 1; --j) {
				if (--t == 0) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		f = !f;
	}
	return 0;
}
