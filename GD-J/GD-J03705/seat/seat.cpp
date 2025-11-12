#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int LitR = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int nx = 1, ny = 1;
	bool ndir = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == LitR) {
			cout << nx << " " << ny << endl;
			return 0;
		}
		if (ndir) {
			if (ny - 1 < 1) {
				nx++;
				ndir = 0;
			} else {
				ny--;
			}
		} else {
			if (ny + 1 > n) {
				nx++;
				ndir = 1;
			} else {
				ny++;
			}
		}
	} 
	return 0;
}
