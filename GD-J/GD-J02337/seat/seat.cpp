#include <bits/stdc++.h>
// #define int long long
using namespace std;
int r[102], s[11][11];
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t{}, k;
	cin >> n >> m;
	for (int i{1}; i <= n * m; i++)
		cin >> r[i];
	k = r[1];
	sort(r + 1, r + n * m + 1, greater<>());
	for (int j{1}; j <= m; j++)
		if (j & 1)
			for (int i{1}; i <= n; i++)
				s[i][j] = r[++t];
		else
			for (int i{n}; i; i--)
				s[i][j] = r[++t];
	for (int i{1}; i <= n; i++)
		for (int j{1}; j <= m; j++)
			if (s[i][j] == k)
				return cout << j << ' ' << i, 0;
	return 0;
}
