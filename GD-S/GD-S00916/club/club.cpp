#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int c = 1, s = 0;
	char ch = getchar();
	for (;!isdigit(ch);ch = getchar()) if (ch == '-') c = -1;
	for (;isdigit(ch);ch = getchar()) s = (s << 1) + (s << 3) + (ch ^ '0');
	return c * s;
}

const int N = 100010;

int n, dp[N][8], nn;
int club[N][3];

struct A
{
	int a, b, c, max1, max2, max1x, max2x, max3x;
}a[N];

bool cmp(A x, A y)
{
	if (x.max1 > y.max1) return 1;
	else if (x.max1 == y.max1)
	{
		return x.max2 > y.max2;
	}
}

int dfs(int x, int step)
{
	if (x > n) return step;
	int maxx;
	club[x][0] = club[x-1][0];
	club[x][1] = club[x-1][1];
	club[x][2] = club[x-1][2];
	if (club[x-1][0] < nn)
	{
		club[x][0]++;
		maxx = dfs(x + 1, step + a[x].a);
		club[x][0]--;
	}
	if (club[x-1][1] < nn)
	{
		club[x][1]++;
		maxx = max(maxx, dfs(x + 1, step + a[x].b));
		club[x][1]--;
	}
	if (club[x-1][2] < nn)
	{
		club[x][2]++;
		maxx = max(maxx, dfs(x + 1, step + a[x].c));
		club[x][2]--;
	}
	return maxx;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	t = read();
	while (t--)
	{
		n = read();
		nn = n / 2;
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			a[i].a = read();a[i].b = read();a[i].c = read();
		}
		if (n <= 200)
		{
			printf("%d\n", dfs(1, 0));
		}
		else
		{
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1;i <= nn;i++)
				ans += a[i].a;
			printf("%d\n", ans);
		}
	}
	return 0;
}

