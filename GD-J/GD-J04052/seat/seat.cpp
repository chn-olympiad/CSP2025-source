#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int now = a[1];
	sort(a + 1, a + 1 + n * m, greater<>());
	for (int i = 1; i <= m; i++) { // ап 
		if (i & 1) {
			for (int j = 1; j <= n; j++) {
				if (a[(i - 1) * n + j] == now) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
		else {
			for (int j = n; j >= 1; j--) {
				if (a[(i - 1) * n + (n - j + 1)] == now) {
//					cout << (i - 1) * n + (n - j + 1) << endl;
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
