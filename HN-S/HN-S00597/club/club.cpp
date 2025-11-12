#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][4], ans;
void dfs(int step, int sum, int a1, int a2, int a3)
{
	if (step > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (a1 < n / 2)
		dfs(step + 1, sum + a[step][1], a1 + 1, a2, a3);
	if (a2 < n / 2)
		dfs(step + 1, sum + a[step][2], a1, a2 + 1, a3);
	if (a3 < n / 2) 
		dfs(step + 1, sum + a[step][3], a1, a2, a3 + 1);
	return;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
