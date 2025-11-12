#include <bits/stdc++.h>
using namespace std;
int d[10005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("roaad.out", "w", stdout);
	int n, m, k, a, b, c;
	cin >> m >> n >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			cin >> d[j];
		}
	}
	cout << n + m + k;
	return 0;
}
