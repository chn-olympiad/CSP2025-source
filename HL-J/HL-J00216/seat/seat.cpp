#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10;
constexpr int M = 10;

int n, m, a[N * M + 1];
pair<int, int> ans[N * M + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int want = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int x = 1, y = 1, c = 1;
	while (x <= m && y <= n) {
		ans[c++] = make_pair(x, y);
		if (x & 1) {
			if (y < n)
				y++;
			else
				x++;
		} else {
			if (y > 1)
				y--;
			else
				x++;
		}
	}
	for (int i = 1; i <= n * m; i++)
		if (a[i] == want)
			cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}