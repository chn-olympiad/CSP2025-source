#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, m, p[510], non, h = 1, x = 1, s, r = 1, y = 0, c[510];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	s = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%1d", &p[i]);
		x = (x && p[i]);
		y = (y || p[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		if (non >= c[i] || !c[i]) non++, s--;
	}
	for (int i = 1; i <= n; i++)
	{
		r = h;
		h = 1ll * r * i % P;
		printf("%d\n", h);
	}
	if ((m == n) && !x || !y) printf("0");
	else if (x) printf("%d", h);
	else if (m == 1) printf("%d", r);
	else
	{
		int ans = 0;
		sort(p + 1, p + 1 + n);
		do
		{
			int k = 0;
			h = 0;
			for (int i = 1; i <= n; i++)
				if (p[i] && h < c[i]) k++;
				else h++;
			if (k >= m) ans = (ans + 1) % P;
		} while (next_permutation(p + 1, p + 1 + n));
		printf("%d", ans);
	}
	return 0;
}
