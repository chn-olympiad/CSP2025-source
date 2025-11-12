#include<bits/stdc++.h>
using namespace std;
int a[1010],sa[20][20];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	int len = n * m;
	for (int i = 1;i<=len;i++)
	{
		cin >> a[i];
	}
	int xr = a[1];
	sort(a + 1,a + len + 1,cmp);
	int cnt = 0;
	for (int j = 1;j<=m;j++)
	{
		if(j %2== 1)
		{
			for (int i = 1;i<=n;i++)
			{
				cnt++;
				sa[i][j] = a[cnt];
			}
		}
		else if(j % 2 == 0)
		{
			for (int i = n;i>=1;i--)
			{
				cnt++;
				sa[i][j] = a[cnt];
			}
		}
	}
	for (int i = 1;i<=n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if(sa[i][j] == xr)
			{
				cout << j << " " << i;
			}
		}
	}
	return 0;
}

