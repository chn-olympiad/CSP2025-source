#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int t, n, p[N], ans;
pair<int, int> a[N][4];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q[4];
void Insert(int x)
{
	for (int i = p[x] + 1; i <= 3; i++)
	{
		int to = a[x][i].second;
		if (q[to].size() < n / 2)
		{
			q[to].push(make_pair(a[x][i].first - a[x][i + 1].first, x));
			p[x] = i;
			ans += a[x][i].first;
			return;
		}
		else
		{
			int y = q[to].top().second, s = q[to].top().first;
			int d = a[x][i].first - a[x][i + 1].first;
			if (s < d)
			{
				ans += a[x][i].first;
				ans -= a[y][p[y]].first;
				q[to].pop();
				q[to].push(make_pair(d, x));
				p[x] = i;
				Insert(y);
				return;
			}
		}
	}
}
int read()
{
	char c;
	int a = 0;
	while (c = getchar(), !isdigit(c));
	while (isdigit(c))
	{
		a = a * 10 + c - '0';
		c = getchar();
	}
	return a;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--)
	{
		ans = 0;
		memset(p, 0, sizeof p);
		for (int i = 1; i <= 3; i++)
			while (!q[i].empty())
				q[i].pop();
		n = read();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				a[i][j].first = read();
				a[i][j].second = j;
			}
			sort(a[i] + 1, a[i] + 4, greater<pair<int, int>>());
			Insert(i);
		}
		cout << ans << endl;
	}
	return 0;
}
