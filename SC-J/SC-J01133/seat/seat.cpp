#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int a[N];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int now = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1, cur = 1, t = 1;
	while (cur <= n * m && a[cur] != now)
	{
		y += t;
		if (y > n || y < 1)
		{
			if (y > n) y = n, x++;
			else if (y < 1) y = 1, x++;
			t = -t;
		}
		cur++;
	}
	printf("%d %d\n", x, y);
	return 0;
}
