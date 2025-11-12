#include<bits/stdc++.h>
using namespace std;
int n, a[5005], ans;
void dfs(int deep, bool choice, int he, int maxx)
{
	if (deep > n)
	{
		if (he > maxx * 2)
			ans++;
		return;
	}
	if (choice)
	{
		dfs(deep + 1, 1, he + a[deep], max(maxx, a[deep]));
		dfs(deep + 1, 0, he + a[deep], max(maxx, a[deep]));
	}
	else
	{
		dfs(deep + 1, 1, he, maxx);
		dfs(deep + 1, 0, he, maxx);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool allo = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1) allo = 0;
	}
	if (allo)
		cout << (1 << n) - 1 - n - (n - 1) * n / 2;
	else
	{
		dfs(0, 0, 0, 0);
		cout << ans / 2;
	}
	return 0;
}
