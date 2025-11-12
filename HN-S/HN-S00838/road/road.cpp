#include <bits/stdc++.h>
using namespace std;
long long n,m;
int k;
vector<int> u,v,w,c;
int a[10][10];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 0;i < k; i++)
	{
		cin >> c[i];
		for (int j = 0; j < n;j++)
			cin >> a[i][j];
	}
	return 0;
}
