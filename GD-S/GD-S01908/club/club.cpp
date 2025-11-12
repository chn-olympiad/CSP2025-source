#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN][3];
vector<int> p[3];

pair<int, int> Find(int x, int y, int z)
{
	int mx = max(x, max(y, z));
	int d = x + y + z - mx - min(x, min(y, z));
	if (x == mx)
		return make_pair(0, d);
	else if (y == mx)
		return make_pair(1, d);
	return make_pair(2, d);
}

int main()
{
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 3; i++)
			p[i].clear();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", a[i] + j);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			pair<int, int> x = Find(a[i][0], a[i][1], a[i][2]);
			ans += a[i][x.first];
			int dif = a[i][x.first] - x.second;
			p[x.first].push_back(dif);
		}
		for (int i = 0; i < 3; i++)
		{
			if ((int)p[i].size() > n / 2)
			{
				sort(p[i].begin(), p[i].end());
				int d = p[i].size() - (n / 2);
				for (int j = 0; j < d; j++)
					ans -= p[i][j];
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
