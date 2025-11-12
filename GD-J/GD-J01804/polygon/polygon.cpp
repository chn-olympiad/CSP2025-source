#include <bits/stdc++.h>
using namespace std;
int a[5005], n, mai, ans;
bool ch[5005];
void dfs(int step)
{
	if (step == n + 1)
	{
		int cnt = 0, maxn = 0, he = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ch[i])
			{
				cnt++;
				maxn = max(a[i], maxn);
				he += a[i];
			}
		}
		if (cnt >= 3 && he > maxn * 2)
		{
			ans++;
		}
		return;
	}
	ch[step] = true;
	dfs(step + 1);
	ch[step] = false;
	dfs(step + 1);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mai = max(mai, a[i]);
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	if (mai == 1)
	{
		int ans2 = 1;
		for (int i = 4; i <= n; i++)
		{
			ans2 *= 2;
			ans2 += (i - 1) * (i - 2) / 2;
		}
		cout << ans2;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
