#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, s, k, r, c, cnt = 0;
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
	for(int i = 1; i <= n * m; ++i) scanf("%d", &a[i]);
	s = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	c = 1, r = 0;
	while(cnt < n * m)
	{
		++cnt;
		if(c % 2 == 1)
		{
			if(r < n) ++r;
			else ++c;
		}
		else
		{
			if(r > 1) --r;
			else ++c;
		}
		if(a[cnt] == s) break;
	}
	printf("%d %d", c, r);
	return 0;
}
