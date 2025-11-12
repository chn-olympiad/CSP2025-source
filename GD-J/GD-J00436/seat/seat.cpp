#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], ans[105];
bool cmp(int x, int y)
{
	return x > y;
}
bool pd = 0;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int rs = n*m;
	for (int i = 1; i <= rs; i ++)
		cin >> ans[i];
	int cj = ans[1];
	sort (ans+1, ans+rs+1, cmp);
	for (int i = 1; i <= rs; i ++)
	{
		if (cj == ans[i])
		{
			cj = i;
			break;
		}	
	}
	int k = 1;
	for (int i = 1; i <= m; i ++)
	{
		if (pd == 0)
		{
			if (i % 2 == 1)
			{
				for (int j = 1; j <= n; j ++)
				{
					if (k == cj)
					{
						cout << i << " " << j;
						pd = 1;
						break;
					}
					a[i][j] = ans[k];
					k ++;
				}
			}
			else
			{
				for (int j = n; j >= 1; j --)
				{
					if (k == cj)
					{
						cout << i << " " << j;
						pd = 1;
						break;
					}
					a[i][j] = ans[k];
					k ++;
				}
			}
		}
		else 
			break;
	}
	return 0;
}
