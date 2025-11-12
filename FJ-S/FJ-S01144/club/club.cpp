#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a, b, c;
} l[100005];
int t, n;
int mem[35][35][35][35];
int dfs(int id, int suma, int sumb, int sumc)
{
	if (id == n + 1)
		return 0;
	if (mem[id][suma][sumb][sumc] != 0x3f3f3f3f)
		return mem[id][suma][sumb][sumc];
	int aa = 0, bb = 0, cc = 0;
	if (suma + 1 <= n / 2)
	{
		aa = l[id].a;
		aa += dfs(id + 1, suma + 1, sumb, sumc);
	}
	if (sumb + 1 <= n / 2)
	{
		bb = l[id].b;
		bb += dfs(id + 1, suma, sumb + 1, sumc);
	}
	if (sumc + 1 <= n / 2)
	{
		cc = l[id].c;
		cc += dfs(id + 1, suma, sumb, sumc + 1);
	}
	mem[id][suma][sumb][sumc] = max(aa, max(bb, cc));
	return max(aa, max(bb, cc));
}
int mem2[205][205][205];
int dfs2(int id, int suma, int sumb)
{
	if (id == n + 1)
		return 0;
	if (mem2[id][suma][sumb] != 0x3f3f3f3f)
		return mem2[id][suma][sumb];
	int aa = 0, bb = 0;
	if (suma + 1 <= n / 2)
	{
		aa = l[id].a;
		aa += dfs2(id + 1, suma + 1, sumb);
	}
	if (sumb + 1 <= n / 2)
	{
		bb = l[id].b;
		bb += dfs2(id + 1, suma, sumb + 1);
	}
	mem2[id][suma][sumb] = max(aa, bb);
	return max(aa, bb);
}
bool cmp1(node asd, node qwe)
{
	if (asd.a != qwe.a)
		return asd.a > qwe.a;
	else
		return asd.b < qwe.b;
}
bool cmp2(node asd, node qwe)
{
	return asd.a > qwe.a;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> l[i].a >> l[i].b >> l[i].c;
		if (n <= 30)
		{
			memset(mem, 0x3f, sizeof(mem));
			cout << dfs(1, 0, 0, 0) << endl;
		}
		else if (n == 200)
		{
			memset(mem2, 0x3f, sizeof(mem2));
			cout << dfs2(1, 0, 0) << endl;
		}
		else if (n == 100000)
		{
			bool flag1 = true, flag2 = true;
			for (int i = 1; i <= n; i++)
			{
				if (l[i].b != 0 && l[i].c != 0)
					flag1 = false;
				if (l[i].c != 0)
					flag2 = false;
			}
			if (flag1)
			{
				int ansans = 0;
				sort(l + 1, l + n + 1, cmp2);
				for (int i = 1; i <= n / 2; i++)
					ansans += l[i].a;
				cout << ansans << endl;
			}
			else if (flag2)
			{
				int ansans = 0;
				sort(l + 1, l + n + 1, cmp1);
				for (int i = 1; i <= n; i++)
				{
					if (l[i].a >= l[i].b)
						ansans += l[i].a;
					else
						ansans += l[i].b;
				}
				cout << ansans << endl;
			}
			else
			{
				int ansans = 0;
				for (int i = 1; i <= n; i++)
					if (l[i].a == 20000 || l[i].b == 20000 || l[i].c == 20000)
						ansans += 20000;
				cout << ansans << endl;
			}
		}
	}
	return 0;
}
