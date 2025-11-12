#include <bits/stdc++.h>
using namespace std;
int n, m, R, a[105], cnt;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	swap(n, m);
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	R = a[1];
	sort(a + 1, a + 1 + (n * m), greater<int>());
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) {
			if (a[++cnt] == R) {
				if (i % 2 == 1) cout << i << ' ' << j << endl;
				else cout << i << ' ' << m - j + 1 << endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}