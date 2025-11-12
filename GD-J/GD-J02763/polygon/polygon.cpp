#include<bits/stdc++.h>
using namespace std;
int a[5005], ans = 0, n;
void dfs(int pos, int maxn, int sum)
{
	if(pos == n + 1)
	{
		if(sum > 2 * maxn)
		{
			ans ++;
			ans %= 998244353;
		}
		return ;
	}
	dfs(pos + 1, max(maxn, a[pos]), sum + a[pos]);
	dfs(pos + 1, maxn, sum);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
} 
