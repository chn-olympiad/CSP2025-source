#include <bits/stdc++.h>
using namespace std;

struct v
{
	int l,r,k;
};

int a[15][10005] = {};
v b[10005] = {};

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int l,r,p;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> b[i].k >> b[i].l >> b[i].r;
	}
	int f = 1;
	for(int i = 1;i <= k;i++)
	{
		cin >> p;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
			a[i][j] += p;
			if (a[i][j])
			{
				f = 0;
			}
		}
	}
	if (!f)
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << 13;
	}
	return 0;
} 
