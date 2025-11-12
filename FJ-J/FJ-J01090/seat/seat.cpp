#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], b[15][15];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) cin >> a[i];
	int s = a[1], l = 1, r = 0, cnt = 1;
	sort(a + 1, a + 1 + n * m, cmp);
	while (cnt <= n * m)
	{
		r ++; l --;
		while (l + 1 <= n) b[++ l][r] = a[cnt ++];
		r ++; l ++;
		while (l - 1 >= 1) b[-- l][r] = a[cnt ++];
	}
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (b[i][j] == s)
			{
				cout << j << " " << i << endl;
				return 0;
			}
}
