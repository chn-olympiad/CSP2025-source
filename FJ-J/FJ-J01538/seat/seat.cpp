#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], mp[15][15];
int ans;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	ans = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1, tmp = 1;
	while(y <= m)
	{
		while(x <= n)
		{
			mp[x][y] = a[tmp];
			tmp++;
			if(mp[x][y] == ans)
			{
				printf("%d %d\n", y, x);
//				for(int i = 1; i <= n; i++)
//				{
//					for(int j = 1; j <= m; j++)
//						cout << mp[i][j] << " ";
//					cout << endl;
//				}
				return 0;
			}
			x++;
		}
		x--;
		y++;
		while(x >= 1)
		{
			mp[x][y] = a[tmp];
			tmp++;
			if(mp[x][y] == ans)
			{
				printf("%d %d\n", y, x);
//				for(int i = 1; i <= n; i++)
//				{
//					for(int j = 1; j <= m; j++)
//						cout << mp[i][j] << " ";
//					cout << endl;
//				}
				return 0;
			}
			x--;
		}
		x++;
		y++;
		while(x <= n)
		{
			mp[x][y] = a[tmp];
			tmp++;
			if(mp[x][y] == ans)
			{
				printf("%d %d\n", y, x);
//				for(int i = 1; i <= n; i++)
//				{
//					for(int j = 1; j <= m; j++)
//						cout << mp[i][j] << " ";
//					cout << endl;
//				}
				return 0;
			}
			x++;
		}
		x--;
		y++;
		while(x >= 1)
		{
			mp[x][y] = a[tmp];
			tmp++;
			if(mp[x][y] == ans)
			{
				printf("%d %d\n", y, x);
//				for(int i = 1; i <= n; i++)
//				{
//					for(int j = 1; j <= m; j++)
//						cout << mp[i][j] << " ";
//					cout << endl;
//				}
				return 0;
			}
			x--;
		}
		x++;
		y++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
