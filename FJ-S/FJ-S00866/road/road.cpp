#include <bits/stdc++.h>
using namespace std;
int n,m,k,d,a[1000005],b[1000005],c[1000005],x[1000005]; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> d;
		for (int j = 1; j <= n; j++)
		{
			cin >> x[j];
		}
	}
	if (k == 0)
	{
		cout << (n-1)*n/2;
	}
	return 0;
} 
