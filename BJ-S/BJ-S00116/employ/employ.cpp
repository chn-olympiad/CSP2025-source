#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
bool maps[505], vis[505];
int c[505], ans, a[505];
void dfs(int id)
{
	if(id > n)
	{
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(cnt2 >= c[a[i]]) cnt2 ++;
			else if(maps[i] == 0) cnt2 ++;
			else cnt1 ++;
		}
		if(cnt1 >= m)
		{
			ans ++;
		}
		return;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(!vis[i])
		{
			a[id] = i;
			vis[i] = 1;
			dfs(id + 1);
			vis[i] = 0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		char ch;
		cin >> ch;
		maps[i] = ch - '0';
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
