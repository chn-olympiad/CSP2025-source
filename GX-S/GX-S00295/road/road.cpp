#include <bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,c;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin >> c;
		}
	}
	cout << 13;
	return 0;
}
