#include <bits/stdc++.h>
using namespace std;
struct int3
{
	int _1 = 0;
	int _2 = 0;
	int _3 = 0;
};
int dfs3(vector<int3> a, int t, int n, int c[3]);
int dfs2(vector<int3> a, int t, int n, int c[2]);
inline int max(int x, int y, int z);
bool cmp(int3 x, int3 y);
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int q = 0;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int n = 0, ans = 0;
		scanf("%d", &n);
		int type = 3;
		vector<int3> a(n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d%d%d", &a[j]._1, &a[j]._2, &a[j]._3);
			if (type == 3)
			{
				if (a[j]._2 != 0)
					type = 2;
				if (a[j]._3 != 0)
					type = 1;
			}
			else if (type == 2)
			{
				if (a[j]._3 != 0)
					type = 1;
			}
		}
		if (type == 3)
		{
			sort(a.begin(), a.end(), cmp);
			for (int j = 0; j < n / 2; ++j)
				ans += a[j]._1;
		}
		else if (type == 2)
		{
			int c[2] = {0, 0};
			ans = dfs2(a, 0, n, c);
		}
		else
		{
			int c[3] = {0, 0, 0};
			ans = dfs3(a, 0, n, c);
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
bool cmp(int3 x, int3 y)
{
	return x._1 > y._1;
}
inline int max(int x, int y, int z)
{
	if (x > y)
		if (x > z)
			return x;
		else
			return z;
	else
		if (y > z)
			return y;
		else
			return z;
}
int dfs3(vector<int3> a, int t, int n, int c[3])
{
	if (t == n)
		return 0;
	int x1 = 0, x2 = 0, x3 = 0;
	if (c[0] < n / 2)
	{
		++c[0];
		x1 = dfs3(a, t + 1, n, c) + a[t]._1;
		--c[0];
	}
	if (c[1] < n / 2)
	{
		++c[1];
		x2 = dfs3(a, t + 1, n, c) + a[t]._2;
		--c[1];
	}
	if (c[2] < n / 2)
	{
		++c[2];
		x3 = dfs3(a, t + 1, n, c) + a[t]._3;
		--c[2];
	}
	return max(x1, x2, x3);
}
int dfs2(vector<int3> a, int t, int n, int c[2])
{
	if (t == n)
		return 0;
	int x1 = 0, x2 = 0, x3 = 0;
	if (c[0] < n / 2)
	{
		++c[0];
		x1 = dfs2(a, t + 1, n, c) + a[t]._1;
		--c[0];
	}
	if (c[1] < n / 2)
	{
		++c[1];
		x2 = dfs2(a, t + 1, n, c) + a[t]._2;
		--c[1];
	}
	return max(x1, x2);
}
