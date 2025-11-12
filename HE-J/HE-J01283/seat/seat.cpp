#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], b[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int xiaor = a[1];
	sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++) b[i] = a[n * m + 1 - i];
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				if (b[(i - 1) * m + j] == xiaor) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else {
			for (int j = m; j >= 1; j--) {
				 if (b[(i - 1) * m + (m + 1 - j)] == xiaor) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
