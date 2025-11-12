#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int T, n, a[N][3], cnt[3], ans, p, c[2];
vector<int> vec[3];
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int get(int x) {
	int res = 0;
	for (int i = 1; i < 3; i ++ )
		if (a[x][i] > a[x][res]) res = i;
	return res;
}
bool cmp(int x, int y) {
	c[0] = c[1] = 1e9;
	for (int i = 0; i < 3; i ++ ) {
		if (i != p) {
			c[0] = min(c[0], a[x][p] - a[x][i]);
			c[1] = min(c[1], a[y][p] - a[y][i]);
		}
	}
	return c[0] < c[1];
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T -- ) {
		n = read();
		for (int i = 1; i <= n; i ++ )
			for (int j = 0; j < 3; j ++ ) a[i][j] = read();
		cnt[0] = cnt[1] = cnt[2] = ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			int x = get(i);
			cnt[x] ++, ans += a[i][x], vec[x].push_back(i);
		}
		if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
			for (int i = 0; i < 3; i ++ ) vec[i].clear();
			cout << ans << '\n';
			continue;
		}
		for (p = 0; p < 3; p ++ ) {
			if (cnt[p] > n / 2) {
				sort(vec[p].begin(), vec[p].end(), cmp);
				int hh = 0;
				while (cnt[p] > n / 2) {
					cnt[p] --; int j = vec[p][hh], mx = 0;
					for (int i = 0; i < 3; i ++ )
						if (i != p) mx = max(mx, a[j][i]);
					ans = ans - a[j][p] + mx, hh ++;
				}
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < 3; i ++ ) vec[i].clear();
	}
	return 0;
}
