#include <bits/stdc++.h>
using namespace std;
struct node {
	int s, num;
} a[1010];
bool cmp (node x, node y) {
	return x.s > y.s;
}
int mp[101][101];
int ansx, ansy, n, m, step;
void dfs(int x, int y) {
	mp[x][y] = a[++step].s;
	if (a[step].num == 1) {
		ansx = x, ansy = y;
		return;
	}
	if (y % 2 == 1 && x == n) dfs(x, y + 1);
	else if (y % 2 == 0 && x == 1) dfs(x, y + 1);
	else if (y % 2 == 1) dfs(x + 1, y);
	else if (y % 2 == 0) dfs(x - 1, y);
	return;
}
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	a[1].num = 1;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i].s;
	}
	sort(a + 1, a + n * m + 1, cmp);
	dfs(1, 1);
	cout << ansy << ' ' << ansx;
	return 0;
}