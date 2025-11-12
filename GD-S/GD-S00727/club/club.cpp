#include <bits/stdc++.h>
using namespace std;
int n, t, v[10005][4];
long long dfs(int p, int a, int b, int c)
{
	if (p > n)
	{
		return 0;
	}
	int ans1 = 0, ans2 = 0, ans3 = 0;
	if (a + 1 <= n/2)
	{
		ans1 = dfs(p+1, a+1, b, c)+v[p][1];
	}
	if (b + 1 <= n/2)
	{
		ans2 = dfs(p+1, a, b+1, c)+v[p][2];
	}
	if (c + 1 <= n/2)
	{
		ans3 = dfs(p+1, a, b, c+1)+v[p][3];
	}
	//cout << p << " " << a  << " " << b  << " " << c << " ";
	//cout << ans1 << " " << ans2 << " " << ans3 << endl;
	return max(ans1, max(ans2, ans3));
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i][1] >> v[i][2] >> v[i][3];
		}
		cout << max(dfs(2, 0, 1, 0)+v[1][2], max(dfs(2, 1, 0, 0)+v[1][1], dfs(2, 0, 0, 1)+v[1][3]))<< endl;
	}
	return 0;
}
