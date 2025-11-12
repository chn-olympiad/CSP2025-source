#include <bits/stdc++.h>
using namespace std;
int t, n, a[100020][3], maxs, ans, f[100020][3], cnt[5];
void dfs(int k)
{
	if (k == n + 1)
	{
		int sum = 0;
		for (int i = 1; i <= n ; i ++)
		{
			for (int j = 1; j <= 3; j  ++) sum += a[i][j] * f[i][j];
		}
		
		ans = sum;
		maxs = max(ans, maxs);
		return;
	}
	for (int j = 1; j <= 3; j ++)
	{
		if (cnt[j] >= n / 2) continue;
		f[k][j] = 1;
		cnt[j] ++;
		dfs(k + 1);
		f[k][j] = 0;
		cnt[j] --;
	} 
}
int main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= 3; j ++)
			{	cin >> a[i][j]; f[i][j] = 0;}
		}
		for (int i = 1; i <= 4; i ++ ) cnt[i] = 0;
		maxs = ans = 0;
		dfs(1);
		cout << maxs << endl;
	}
	return 0;
}
