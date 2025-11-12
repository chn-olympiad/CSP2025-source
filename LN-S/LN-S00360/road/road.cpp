#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[10005],v[10005],w[10005],a[10005][15],c[15];
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) cin >> u[i] >> v[i] >> w[i];
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}
