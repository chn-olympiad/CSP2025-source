#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15], a[15][10005];
vector <int> u, v, w;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		u.push_back(a);
		v.push_back(b);
		w.push_back(c);
	}
	for (int j = 1; j <= k; j++)
	{
		cin >> c[j];
		for (int i = 1; i <= n; i++)
		{
			cin >> a[j][i];
		}
	}
	
	
	
	return 0;
}
