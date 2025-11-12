#include<bits/stdc++.h>
using namespace std;

int n, t, ans;
int a1[100005], a2[100005], a3[100005];
bool vis[100005];

void dfs(int now, int c1, int c2, int c3, int sum)
{
	if (now == n + 1)
	{
		ans = max(ans, sum);
		return ;
	}
	if (c1 < n / 2) dfs(now + 1, c1 + 1, c2, c3, sum + a1[now]);
	if (c2 < n / 2) dfs(now + 1, c1, c2 + 1, c3, sum + a2[now]);
	if (c3 < n / 2) dfs(now + 1, c1, c2, c3 + 1, sum + a3[now]);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t --)
	{
		ans = 0;
		memset(vis, 0, sizeof vis);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		if (n <= 10) dfs(1, 0, 0, 0, 0);
		else 
		{
			if (a2[1] == 0 && a3[1] == 0)
			{
				sort(a1 + 1, a1 + 1 + n);
				for (int i = n; i >= n / 2; i --)
				{
					ans += a1[i];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}