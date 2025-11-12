#include <bits/stdc++.h>
using namespace std;
int n, m, x=1, y, num, score_r;
int a[105];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
		cin >> a[i];
	score_r=a[1];
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1;i <= n*m;i++)
	{
		if (!num)
		{
			if (y == n)
			{
				x++;
				num = 1;
			}
			else
				y++;
		}
		else if (num)
		{
			if (y == 1)
			{
				x++;
				num = 0;
			}
			else
				y--;
		}
		if (a[i]==score_r)
		{
			cout << x << " " << y;
			break;
		}
	}
	return 0;
}
