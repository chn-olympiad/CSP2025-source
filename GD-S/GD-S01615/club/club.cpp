#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x, y, z;
}a[100005];
int co, n;
bool cmp(node x, node y)
{
	return x.x > y.x;
}
bool cmp2(node x, node y)
{
	return abs(x.x - x.y) > abs(y.x - y.y);
}
void dfs(int step, int da, int xiao, int pi, int ans)
{
	if (step == n + 1)
	{
		co = max(co, ans);
		return;
	}
	if (da < n / 2)
	{
		dfs(step + 1, da + 1, xiao, pi, ans + a[step].x);
	}
	if (xiao < n / 2)
	{
		dfs(step + 1, da, xiao + 1, pi, ans + a[step].y);
	}
	if (pi < n / 2)
	{
		dfs(step + 1, da, xiao, pi + 1, ans + a[step].z);
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		bool flaga = true, flagb = true;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y != 0)
			{
				flaga = false;
			}
			if (a[i].z != 0)
			{
				flaga = false;
				flagb = false;
			}
		}
		if (flaga)
		{
			sort(a + 1, a + n + 1, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)
			{
				ans += a[i].x;
			}
			cout << ans << endl;
		}
		else if (flagb)
		{
			int ans = 0;
			sort(a + 1, a + n + 1, cmp2);
			int da = 0, xiao = 0, pi = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i].x - a[i].y > 0)
				{
					if (da < n / 2)
					{
						da++;
						ans += a[i].x;
					}
					else
					{
						xiao++;
						ans += a[i].y;
					}
				}
				else if (a[i].x - a[i].y < 0)
				{
					if (xiao < n / 2)
					{
						xiao++;
						ans += a[i].y;
					}
					else
					{
						da++;
						ans += a[i].x;
					}
				}
				else
				{
					ans += a[i].x;
				}
			}
			cout << ans << endl;
		}
		else
		{
			co = 0;
			dfs(1, 0, 0, 0, 0);
			cout << co << endl;
		}
	}
	return 0;
}
