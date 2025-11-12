#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u[100000+10],v[100000+10],w[100000+10];
	int c[100000+10];
	int p[100000+10][100000+10];
	for (int i = 1;i <= m;i++) cin >> u[i] >> v[i] >> w[i];
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
	}
	return 0;
}
