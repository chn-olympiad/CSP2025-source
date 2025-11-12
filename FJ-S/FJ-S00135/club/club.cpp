#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1;
int n;
ll ans;

struct node
{
	int r, p, q;
};

node a[maxn];

void solve()
{
	for(int i = 1; i <= n; i++)
	{
		int max_u = max(max(a[i].r, a[i].p), max(a[i].r, a[i].q));
		ans += max_u;
	}
}

ll dfs(int depth, int cnt_r, int cnt_p, int cnt_q)
{
	if(depth > n)
	{
		return 0;
	}
	
	ll u, v, w;
	u = v = w = 0;
	if(cnt_r < n / 2)
	{
		u = dfs(depth + 1, cnt_r + 1, cnt_p, cnt_q) + a[depth].r;
	}
	if(cnt_p < n / 2)
	{
		v = dfs(depth + 1, cnt_r, cnt_p + 1, cnt_q) + a[depth].p;
	}
	if(cnt_q < n / 2)
	{
		w = dfs(depth + 1, cnt_r, cnt_p, cnt_q + 1) + a[depth].q;
	}
	ll t = max(max(u, v), max(u, w));
	return t;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].r, &a[i].p, &a[i].q);
		}
		solve();
		ans = max(ans, dfs(1, 0, 0, 0));
		printf("%lld", ans);
	}
	return 0;
}
