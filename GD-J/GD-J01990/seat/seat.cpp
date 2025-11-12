#include<bits/stdc++.h>
using namespace std;
int n,m,a[121],st[11][11];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	sort(a + 2,a + n * m + 1,cmp);
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1;j <= n;j++)
			{
				if (a[(i - 1) * n + j + 1] < a[1])
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			int cnt = 0;
			for (int j = n;j >= 1;j--)
			{
				cnt++;
				if (a[(i - 1) * n + cnt + 1] < a[1])
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}

