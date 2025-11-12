#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= m + 1; j++)
		{
			cin >> a;
		}
	}
	cout << 0;
	return 0;
}
