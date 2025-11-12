#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[5005], ans;
bool vis[5005];


void dfs(int k, int p, int sum, int mxn)
{
	if (sum > (mxn << 1))++ans;
	
	if (k > n)return ;
	
	for (int i = p; i <= n; ++i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(k + 1, i, sum + a[i], max(mxn, a[i]));
			vis[i] = 0;
		}
	}
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	dfs(1, 1, 0, 0);
	cout << ans;
	return 0;
}
