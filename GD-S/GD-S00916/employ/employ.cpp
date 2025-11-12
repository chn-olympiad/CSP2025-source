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

const int N = 510;

int n, m, c[N];

int dfs(int x, int re)
{
	if (x > n) return 1;
	if (c[x] <= re) return 0;
	return dfs(x + 1, re + 1) + dfs(x + 1, re);
}

int main()
{
	cin.tie(0);
	n = read();m = read();
	string s;
	cin >> s;
	for (int i = 1;i <= n;i++)
	{
		c[i] = read();
	}
	printf("%d", dfs(1, 0));
}

