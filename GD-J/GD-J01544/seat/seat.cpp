#include <bits/stdc++.h>
#define endl putchar('\n')
#define pii pair<int, int>
using namespace std;
int read()
{
	char ch = getchar();
	int sum = 0, f = 1;
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 10) return putchar(x + '0'), void();
	write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 15;
int n, m;
pii a[N * N];
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1;i <= n * m;i++) a[i] = {read(), i};
	sort(a + 1, a + n * m + 1, greater<pii>());
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i].second == 1)
		{
			int numl = (i - 1) / n + 1;
			int numh = i - (numl - 1) * n;
			if (numl % 2 == 0) numh = n - numh + 1;
			write(numl), putchar(' '), write(numh);
			return 0;
		}
	}
	return 0;
}
/*
Íí°²£¬LYD¡£
*/
