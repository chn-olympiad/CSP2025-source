#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int n, m, c[505], a[505], ans;
bool can[505], used[505];

void dfs(int step)
{
	if (step > n)
	{
		int cnt = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!can[i])
				cnt++;
			else
			{
				if (cnt >= c[a[i]])
					cnt++;
				else
					cnt1++;
			}
		}
		ans += (cnt1 >= m);
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!used[i])
		{
			used[i] = true;
			a[step] = i;
			dfs(step + 1);
			used[i] = false;
		}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%1d", &can[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	if (m == n)
	{
		bool flag = 1;
		for (int i = 1; i <= n; i++)
			flag &= can[i], flag &= c[i];
		if (flag == 0)
			printf("0");
		else
		{
			int ans = 1;
			for (int i = 2; i <= n; i++)
				ans = (1ll * ans * i) % mod;
			printf("%d", ans);
		}
	}
	else if (n <= 18)
	{
		dfs(1);
		printf("%d", ans);
	}
	else if (m == 1)
	{
		sort(c + 1, c + n + 1, greater<int>());
		int cnt = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (can[i] != 0)
				break;
			cnt++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (c[i] <= cnt)
				break;
			cnt1++;
		}
		int ans = cnt1;
		for (int i = 2; i < n; i++)
			ans = (1ll * ans * i) % mod;
		printf("%d", ans);
	}
	else
	{
		int ans = 1, cnt = 0, cnt1 = 0, minn = 1e9;
		sort(c + 1, c + n + 1, greater<int>());
		for (int i = 1; i <= n; i++)
			cnt += (c[i] == 0);
		if (n - cnt < m)
		{
			printf("0");
			return 0;
		}
		for (int i = 1; i <= n; i++)
			cnt1 += (c[i] > cnt);
		for (int i = 1; i <= n; i++)
			if (c[i] != 0)
				minn = min(minn, c[i]);
		if (cnt1 >= m || cnt < minn)
			for (int i = 1; i <= n; i++)
				ans = (1ll * ans * i) % mod;
		else
		{
			for (int i = 1; i <= n - cnt + minn; i++)
				ans = (1ll * ans * i) % mod;
			for (int i = 1; i <= cnt - minn; i++)
				ans = (1ll * ans * i) % mod;
		}
		printf("%d", ans);
	}
	return 0;
}
