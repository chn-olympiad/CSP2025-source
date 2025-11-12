#include<bits/stdc++.h> 
using namespace std;
int n, m, c;
struct aa
{
	int id, sum;
};
aa a[15];
bool cmp(const aa &b, const aa &c)
{
	return b.sum>c.sum;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++)
	{
		cin >> a[i].sum;
		a[i].id=i;
	}
	sort(a+1, a+1+n*m, cmp);
	for (int i=1; i<=n; i++)
	{
		
		if (i%2)
		{
			for (int j=1; j<=m; j++)
			{
				c++;
				if (a[c].id==1)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j=m; j>=1; j--)
			{
				c++;
				if (a[c].id==1)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
