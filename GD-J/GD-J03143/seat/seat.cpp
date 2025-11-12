#include <bits/stdc++.h>
using namespace std;
int n, m, t, cnt, y = 1, a[1005], b[105][105];
bool cmp(int x, int y) {return x > y;}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int x = 1; x <= m; ++x) {
		if (x % 2) {
			y = 1;
			while (y <= n) {
				cnt++;
				b[x][y] = a[cnt];
//				cout << 1 << " x=" << x << " y=" << y << " cnt=" << cnt << " a[cnt]=" << a[cnt] << '\n';
				++y;
			}
			continue;
		}
		y = n;
		while (y >= 1) {
			cnt++;
			b[x][y] = a[cnt];
//			cout << 2 << " x=" << x << " y=" << y << " cnt=" << cnt << " a[cnt]=" << a[cnt] << '\n';
			--y;
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (b[i][j] == t) {
				cout << i << ' ' << j;
				return 0;
			}
	return 0;
}
