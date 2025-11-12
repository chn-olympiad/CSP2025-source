#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int maxn = 5e3 + 1;
int a[maxn], pre[maxn];
int n;
ll ans;

void dfs(int depth, int sum, int max_stick, int cnt)
{
	if(depth > n)
	{
		if(cnt >= 3)
		{
			if(sum > max_stick * 2)
			{
				ans = (ans + 1) % mod;
			}
		}
		return;
	}
	if(cnt + (n - depth + 1) < 3)
	{
		return;
	}
	dfs(depth + 1, sum, max_stick, cnt);
	dfs(depth + 1, sum + a[depth], max(max_stick, a[depth]), cnt + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	dfs(1, 0, 0, 0);
	printf("%lld", ans);
	return 0;
}
