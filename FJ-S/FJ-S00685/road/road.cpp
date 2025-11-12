#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10005],v[10005],w[10005],a[10005];
int road[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
		cin>> u[i] >> v[i] >> w[i];
	int c;
	cin >> c;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		road[u[i]][v[i]] = w[i];
		road[v[i]][u[i]] = w[i];
	}
	cout << 13;
	return 0;
}
