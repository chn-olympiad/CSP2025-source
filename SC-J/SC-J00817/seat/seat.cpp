#include <iostream>
#include <algorithm>
#define maxn 105
using namespace std;
int n, m, t, k, p, a[maxn], mp[15][15];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	t = n * m;
	for (int i = 1; i <= t; i++)
		cin >> a[i];
	k = a[1];
	sort(a + 1, a + t + 1);
	reverse(a + 1, a + t + 1);
	for (int x = 0, i = 1; i <= n; i++)
		if (i & 1) for (int j = 1; j <= m; j++) mp[i][j] = a[++x];
		else for (int j = m; j >= 1; j--) mp[i][j] = a[++x];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[i][j] == k) cout << i << " " << j << endl, exit(0);
	return 0;
}