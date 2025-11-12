#include<bits/stdc++.h>
using namespace std;
int t, n, a[500005][3], dan;
void dfs(int deep, int choice, int one, int two, int thr, int ans)
{
	if (deep > n)
	{
		if (one <= n / 2 && two <= n / 2 && thr <= n / 2 && ans > dan)
			dan = ans;
		return;
	}
	if (choice == 1)
	{
		dfs(deep + 1, 1, one + 1, two, thr, ans + a[deep][choice]);
		dfs(deep + 1, 2, one + 1, two, thr, ans + a[deep][choice]);
		dfs(deep + 1, 3, one + 1, two, thr, ans + a[deep][choice]);
	}
	if (choice == 2)
	{
		dfs(deep + 1, 1, one, two + 1, thr, ans + a[deep][choice]);
		dfs(deep + 1, 2, one, two + 1, thr, ans + a[deep][choice]);
		dfs(deep + 1, 3, one, two + 1, thr, ans + a[deep][choice]);
	}
	if (choice == 3)
	{
		dfs(deep + 1, 1, one, two, thr + 1, ans + a[deep][choice]);
		dfs(deep + 1, 2, one, two, thr + 1, ans + a[deep][choice]);
		dfs(deep + 1, 3, one, two, thr + 1, ans + a[deep][choice]);
	}
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int hahaha = 1; hahaha <= t; hahaha++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		bool allo = 1;
		for (int i = 1; i <= n; i++)
			if (a[i][2] > 0 || a[i][3] > 0)
				allo = 0;
		if (allo)
		{
			int ne[n + 1];
			for (int i = 1; i <= n; i++) ne[i] = a[i][1];
			sort(ne + 1, ne + n + 1, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)
				ans += ne[i];
			cout << ans << endl;
		}
		else
		{
			dan = 0;
			dfs(1, 1, 0, 0, 0, 0);
			dfs(1, 2, 0, 0, 0, 0);
			dfs(1, 3, 0, 0, 0, 0);
			cout << dan << endl;
		}
	}
	return 0;
}
/*
3 
4 
4 2 1 
3 2 4 
5 3 4 
3 5 1 
4 
0 1 0 
0 1 0 
0 2 0 
0 2 0 
2 
10 9 8 
4 0 0 
*/
