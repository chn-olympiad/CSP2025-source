#include <bits/stdc++.h>
using namespace std;

struct Miao
{
	int u, v, w;
}a[1000007];

int b[17];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		 cin >> a[i].u >> a[i].v >> a[i].w; 
	}
	for (int i = 0; i < k; i++)
	{
		cin >> b[i];
	}
	cout << 2 * n * m * k + a[88].u * a[88].v * a[12].w * b[34];
	return 0;
}
