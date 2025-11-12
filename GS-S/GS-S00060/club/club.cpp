#include <iostream>
#include <cstdio>

using namespace std;

int t;
int n, a[100005], b[100005], c[100005], maxn = 0;

void Dfs(int num, int x1, int x2, int x3, int cnt)
{
	if (num > n)
	{
		maxn = max(maxn, cnt);
		return;
	}
	if (x1 < (n / 2))
	{
		Dfs(num + 1, x1 + 1, x2, x3, cnt + a[num]);
	}
	if (x2 < (n / 2))
	{
		Dfs(num + 1, x1, x2 + 1, x3, cnt + b[num]);
	}
	if (x3 < (n / 2))
	{
		Dfs(num + 1, x1, x2, x3 + 1, cnt + c[num]);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		Dfs(1, 0, 0, 0, 0);
		cout << maxn << endl;
	}
	return 0;
}
