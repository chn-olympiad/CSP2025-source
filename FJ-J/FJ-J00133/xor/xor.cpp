#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 1;
int a[maxn];
ll pre[maxn];
vector<pair<int, int>> ok;
vector<pair<int, int>> vis;
int n, k;
ll ans;

void dfs(int depth, ll cnt)
{
	if(depth == ok.size())
	{
		ans = max(ans, cnt);
		return;
	}
	if(cnt + (n - depth + 1) <= ans)
	{
		return;
	}
	dfs(depth + 1, cnt);
	for(int i = 0; i < vis.size(); i++)
	{
		if(vis[i].first == ok[depth].first || vis[i].first == ok[depth].second)
		{
			return;
		}
		if(vis[i].second == ok[depth].first || vis[i].second == ok[depth].second)
		{
			return;
		}
		if(vis[i].first < ok[depth].first)
		{
			if(vis[i].second > ok[depth].first)
			{
				return;
			}
		}
		if(vis[i].first > ok[depth].first)
		{
			if(ok[depth].second > vis[i].first)
			{
				return;
			}
		}
	}
	vis.push_back({ok[depth].first, ok[depth].second});
	dfs(depth + 1, cnt + 1);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == k)
		{
			ans++;
		}
		pre[i] = pre[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			ll t = pre[j] ^ pre[i - 1];
			if(t == k)
			{
				ok.push_back({i, j});
			}
		}
	}
	dfs(0, 0);
	printf("%lld", ans);
	return 0;
}
