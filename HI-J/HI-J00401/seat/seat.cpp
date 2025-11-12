#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[104] = {};
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int v = 0;
	for (int i = 1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	v = a[1];
	sort(a+1,a+n*m+1);
	int x=0,y=0;
	int d = 0;
	for (int i = m*n;i>=1;i--)
	{
		d++;
		if (v == a[i])
		{
			if (d % m == 0)
			{
				x = d/m;
			}
			else x = d/m+1;
			if (x % 2 != 0)
			{
				if (d % m == 0)
				{
					y = m;
				}
				else y = d % m;
			}else if (x % 2 == 0)
			{
				if (d % m == 0)
				{
					y = 1;
				}
				else y = m-d%m+1;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}
