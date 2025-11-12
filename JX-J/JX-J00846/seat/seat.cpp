#include<bits/stdc++.h>
using namespace std;
int a[1000];
int f;
bool flag = 0;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if(i == 1) f = a[i];
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == f)
		{
			cout << x << " " << y;
			return 0;
		}
		else
		{
			if(flag == 0)
			{
				if(y == m)
				{
					flag = 1;
					x++;
				}
				else
				{
					y++;
				}
			}
			else if(flag == 1)
			{
				if(y == 1)
				{
					flag = 0;
					x++;
				}
				else
				{
					y--;
				}
			}
		}
	}
	return 0;
}
