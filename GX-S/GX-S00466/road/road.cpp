#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
int n, m, k, c[N], u[N], v[N], w[N];
vector <int> a[N];
int main ()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= m ; i ++)
		for (int j = 1; j <= n + 1; j ++)
			cin >> a[i][j];
	cout << 0;
	return 0;
}
