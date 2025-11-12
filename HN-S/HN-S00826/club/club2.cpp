#include <bits/stdc++.h>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 5;

int T, n, c[3], ans;
int a[kMaxN][3], t[kMaxN][3];
array<int, 3> b[4]; 
array<array<int, 3>, 3> v[kMaxN]; 

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);	 
	for (cin >> T; T--;) {
		cin >> n;
		ans = 0; 
		c[0] = c[1] = c[2] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			t[i][0] = a[i][0] - max(a[i][1], a[i][2]);
			t[i][1] = a[i][1] - max(a[i][0], a[i][2]);
			t[i][2] = a[i][2] - max(a[i][0], a[i][1]);
			b[0] = {t[i][0], 0, a[i][0]};
			b[1] = {t[i][1], 1, a[i][1]};
			b[2] = {t[i][2], 2, a[i][2]};
			sort(b, b + 3, [](array<int, 3> x, array<int, 3> y) {
				return x[0] > y[0];
			});
			v[i] = {b[0], b[1], b[2]};
		}
		sort(v + 1, v + n + 1, [](array<array<int, 3>, 3> x, array<array<int, 3>, 3> y) {
			if (x[0] != y[0]) return x[0] < y[0];
			if (x[1] != y[1]) return x[1] < y[1];
			return x[2] < y[2];
		});
		for (int i = 1; i <= n; i++) {
			if (c[v[i][0][1]] < n / 2) {
				ans += v[i][0][2];
				c[v[i][0][1]]++;
			} 
			else if (c[v[i][1][1]] < n / 2) {
				ans += v[i][1][2];
				c[v[i][1][1]]++;
			}
			else  {
				ans += v[i][2][2];
				c[v[i][2][1]]++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
