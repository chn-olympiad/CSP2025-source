#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], cnt = 1, st;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	st = a[1];
	sort(a + 1, a + 1 + (n * m), greater());
	for (int j = 1; j <= m; j++) {
		if (j % 2 != 0)
			for (int i = 1; i <= n; i++) {
				if (a[cnt] == st) {
					cout << j << " " << i;
					return 0;
				}
				cnt++;
			} else
			for (int i = n; i >= 1; i--) {
				if (a[cnt] == st) {
					cout << j << " " << i;
					return 0;
				}
				cnt++;
			}
	}
	return 0;
}