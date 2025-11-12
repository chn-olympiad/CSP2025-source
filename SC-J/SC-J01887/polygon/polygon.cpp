#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 998244353;
int a[N], vis[N];
int n, ans;
void dfs(int cur, int mx, int sum, int cnt)
{
	if (sum > mx * 2 && cnt >= 3) ans ++;
	for (int i = cur; i < n; i ++)
	{
		dfs(a[i], max(mx, a[i]), sum + a[i], ++ cnt); 
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++)
	{
		dfs(a[i], a[i], a[i], 1);
	}
	cout << ans;
	return 0;
}