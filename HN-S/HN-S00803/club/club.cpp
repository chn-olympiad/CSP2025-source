#include <bits/stdc++.h>
#define ing long long
using namespace std;
int n, ans = 0;
struct node
{
	int a, b, c;
}a[100000 + 9];//Ren5Jie4Di4Ling5%
void DFS(int u, int c1, int c2, int c3, int op)
{
	if (c1 > n / 2 || c2 > n / 2 || c3 > n / 2)
	{
		return;
	}
	if (u > n)
	{
		ans = max(ans, op);
		return;
	}
	DFS(u + 1, c1 + 1, c2, c3, op + a[u].a);
	DFS(u + 1, c1, c2 + 1, c3, op + a[u].b);
	DFS(u + 1, c1, c2, c3 + 1, op + a[u].c);
	return;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --)
	{
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		DFS(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
