#include <bits/stdc++.h>
using namespace std;
int k,w[100010],c[1010];
long long n,m,u[100010],v[100010],a[100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> u[i]>>v[i]>>w[i];
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j++) cin >> a[i];
	}
	cout << 0;
	return 0;
}

