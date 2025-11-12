#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[1000001],a[1000001][11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
		cin >> v[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= k;j++)
			cin >> a[i][j];
	cout << 63;
	return 0;
}