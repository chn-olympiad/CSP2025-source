#include<bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;

int n, m;
int a[N];
char s[N];
bool vis[N];
long long ans = 0;

void dfs(int now, int sum, int tot)
{
	if (now == n) 
	{
		if (tot >= m) ans = (ans + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (!vis[i])
		{
			if (sum < a[i] && s[now] == '1')
			{
				vis[i] = 1;
				dfs(now + 1, sum, tot + 1);
				vis[i] = 0;
			}
			else 
			{
				vis[i] = 1;
				dfs(now + 1, sum + 1, tot);
				vis[i] = 0;
			}
		}
		
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}