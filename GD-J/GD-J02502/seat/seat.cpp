#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
//int b[11][11];
int r;
int x = 1, y = 0;//xÁÐyÐÐ 
bool p;
bool cmp(int A, int B)
{
	return A > B;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
	{
		scanf("%d", &a[i]);
	}
	r = a[1];
	sort (a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (!p) y++;
		if (p) y--;
		if (y > n)
		{
			y = n;
			x++;
			p = true;
		}
		if (y < 1)
		{
			y = 1;
			x++;
			p = false;
		}
//		b[y][x] = a[i];
		if (a[i] == r)
		{
			printf("%d %d", x, y);
			return 0;
		}
	}
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			printf("%d ", b[i][j]);
//		}
//		cout << endl;
//	}
	return 0;
}
