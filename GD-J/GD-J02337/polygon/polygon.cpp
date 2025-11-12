#include <bits/stdc++.h>
// #define int long long
using namespace std;
int r[5003], n, mx, s;
int dfs(int k)
{
	if (k++ == n)
		return s > (mx << 1);
	int ori{mx};
	if (r[k] > mx)
		mx = r[k];
	s += r[k];
	int res{dfs(k)};
	mx = ori;
	s -= r[k];
	return res + dfs(k);
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i{1}; i <= n; i++)
		cin >> r[i];
	cout << dfs(0);
	return 0;
}

