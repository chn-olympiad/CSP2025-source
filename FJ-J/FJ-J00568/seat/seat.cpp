#include <bits/stdc++.h>
using namespace std;

int a[10005];
int seat[105][105];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int score_R = a[1];
	
	sort(a + 1, a + n * m + 1, greater < int >());

	int x = 1;
	for (int i = 1; i <= m; i++) //c
	{
		if (m % 2 == 0)
		{
			for (int j = 1; j <= n; j++) //r
			{
				seat[i][j] = a[x];
				x++;
			}
		}
		else
		{
			for (int j = n; j >= 1; j--)
			{
				seat[i][j] = a[x];
				x++;
			}
		}
	}
	
	int c, r;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (seat[i][j] == score_R)
			{
				c = i;
				r = j;
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	return 0;
}
