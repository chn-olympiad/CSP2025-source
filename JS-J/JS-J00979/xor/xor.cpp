#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<int> vct(n);
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> vct[i];
	}

	set<int> hasV;
	int tmp = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vct[i] == k)
		{
			ans++;
			tmp = 0;
			hasV.clear();
			continue;
		}

		if (vct[i] == 0)
			continue;

		tmp ^= vct[i];
		if (tmp == k)
		{
			ans++;
			hasV.clear();
			continue;
		}

		if (hasV.count(tmp))
		{
			ans++;
			hasV.clear();
		}
		else
			hasV.insert(tmp^k);
	}

	cout << ans << '\n';

	return 0;
}