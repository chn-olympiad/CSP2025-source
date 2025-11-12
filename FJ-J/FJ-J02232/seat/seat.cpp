#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, tmp = 0, c, r, pos, a[N], ans[N][N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	tmp = a[1];
	sort(a + 1, a + (n * m) + 1);
	reverse(a + 1, a + (n * m) + 1);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == tmp)
		{
			pos = i;
			break;
		}
	c = (pos - 1) / n + 1;
	r = pos % n;
	if (r == 0)
		r = n;
	if (c % 2 == 0)
		r = n - r + 1;
	printf("%d %d", c, r);
	return 0;
}
