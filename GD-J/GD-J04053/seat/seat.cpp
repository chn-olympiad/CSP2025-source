#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
struct node
{
	int ti,x,y;
};
node a[1005];
bool cmp(node a,node b)
{
	return a.ti > b.ti;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i].ti;
		if (i == 1)
		{
			k = a[i].ti;
		}
	}
	int c = n * m;
	sort(a + 1,a + c + 1,cmp);
	int b = 0;
	int sx = 1,sy = 1;
	for (int i = 1;i <= n * m;i++)
	{
		if (b == 0)
		{
			if (sx == n)
			{
				sy++;
				b = 1;
				a[i].x = n;
				a[i].y = sy - 1;
				continue;
			}
			else
			{
				a[i].x = sx;
				a[i].y = sy;
				sx++;
			}
		}
		else if (b == 1)
		{
			if (sx == 1)
			{
				sy++;
				b = 0;
				a[i].x = 1;
				a[i].y = sy - 1;
				continue; 
			}
			else
			{
				a[i].x = sx;
				a[i].y = sy;
				sx--;
			}
		}
	}
	for (int i = 1;i <= n * m;i++)
	{
		if(a[i].ti == k)
		{
			cout << a[i].y << " " << a[i].x;
			break;
		}
	}
	return 0;
}
