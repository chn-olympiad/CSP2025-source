#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[101][101], b[100001];
bool cmp(int x, int y)
{
	return x > y;
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			b[++cnt] = a[i][j];
		}
	}
	sort(b + 1, b + 1 + cnt, cmp);
	int now = 0;
	for(int i = 1; i <= cnt; i++)
	{
		if(b[i] == a[1][1])
		{
			now = i;
			break;
		}
	}
	int x = 1, y = 0;
	for(int i = 1; i <= now; i++)
	{
		if(x % 2 == 1)
		{
			y++;
			if(y > m)
			{
				y = m;
				x++;
			}
		}
		else
		{
			y--;
			if(y < 1)
			{
				y = 1;
				x++;
			}
		}
	}
	cout << x << " " << y;
}
