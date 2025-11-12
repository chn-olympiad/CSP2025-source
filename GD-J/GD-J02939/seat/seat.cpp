#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, R, id_s, k_id = 1;
pair<int, int> s[20005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> s[i].second;
		s[i].first = i;
	}
	R = s[1].second;
	stable_sort(s + 1, s + 1 + n * m, [](pair<int, int> a, pair<int, int> b) -> bool
	{
		return a.second > b.second;
	});
	for (int i = 1; i <= n * m; ++i)
	{
		if (s[i].second == R)
		{
			id_s = i;
		}
	}
	for (int j = 1; j <= m; ++j)
	{
		if ((j & 1) == 1)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (k_id++ == id_s)
				{
					cout << j << ' ' << i;
					exit(0);
				}
			}
		}
		else
		{
			for (int i = n; i >= 1; --i)
			{
				if (k_id++ == id_s)
				{
					cout << j << ' ' << i;
					exit(0);
				}
			}
		}
	}

	return 0;
}
