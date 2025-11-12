#include <bits/stdc++.h>
using namespace std;
int t, a[100005][4];
struct op
{
	int k1, k2;
};
op x1[100005], x2[100005], x3[100005];
bool cmp(op x, op y)
{
	return x.k1 < y.k1;
}
int main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t --)
	{
		int n, h = 0;
		scanf("%d", &n);
		int maxx = n / 2;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= 3; j ++)
			{
				scanf("%d", &a[i][j]);
				if (j == 1) x1[i].k1 = a[i][j], x1[i].k2 = i;
				else if (j == 2) x2[i].k1 = a[i][j], x2[i].k2 = i;
				else if (j == 3) x3[i].k1 = a[i][j], x3[i].k2 = i;
			}
		}
		sort(x1 + 1, x1 + 1 + n, cmp);
		sort(x2 + 1, x2 + 1 + n, cmp);
		sort(x3 + 1, x3 + 1 + n, cmp);
		int i = n, j = n, k = n;
		while(n >= 1)
		{
			int maxn = x1[n].k1, p = 1;
			for (int l = 2; l <= 3; l ++)
			{
				if (l == 2 && x2[j].k1 > maxn) maxn = x2[j].k1, p = 2;
				if (l == 3 && x3[j].k1 > maxn) maxn = x3[j].k1, p = 3;
			}
			if (p == 1 && i - 1 >= maxx)
			{
				i --, h += maxn;
				for (int o = 1; o <= n; o ++)
				{
					if (x2[o].k2 == x1[i].k2) x2[o].k1 = 0;
					if (x3[o].k2 == x1[i].k2) x3[o].k1 = 0;
				}
				sort(x2 + 1, x2 + 1 + n, cmp);
				sort(x3 + 1, x3 + 1 + n, cmp);
			}
			else if (p == 2 && j - 1 >= maxx)
			{
				j --, h += maxn;
				for (int o = 1; o <= n; o ++)
				{
					if (x1[o].k2 == x2[i].k2) x1[o].k1 = 0;
					if (x3[o].k2 == x2[i].k2) x3[o].k1 = 0;
				}
				sort(x1 + 1, x1 + 1 + n, cmp);
				sort(x3 + 1, x3 + 1 + n, cmp);
			}
			else if (p == 3 && k - 1 >= maxx)
			{
				k --, h += maxn;
				for (int o = 1; o <= n; o ++)
				{
					if (x1[o].k2 == x3[i].k2) x1[o].k1 = 0;
					if (x2[o].k2 == x3[i].k2) x2[o].k1 = 0;
				}
				sort(x1 + 1, x1 + 1 + n, cmp);
				sort(x2 + 1, x2 + 1 + n, cmp);
			}
			n --;
		}
		cout << h << "\n";
	}
	return 0;
}
