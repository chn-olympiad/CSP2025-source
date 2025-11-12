#include <bits/stdc++.h>
using namespace std;
int n, m, a[505], ans, mp[505];
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		mp[i] = c;
	}
	if (n > 20)
	{
		cout << 0 << endl;
		return 0;
	}
	do
	{
		int no_loot = 0, loot = 0;
		for (int i = 1; i <= n; i++)
		{
			if (no_loot >= mp[a[i]])
			{
				no_loot++;
			}
			else if (s[i - 1] == '0')
			{
				no_loot++;
			}
			else
			{
				loot++;
			}
		}
		if (loot >= m)
		{
			ans++;
		}
	}
	while (next_permutation(a + 1, a + n + 1));
	cout << ans << endl;
	return 0;
}
/*
3 2
101
1 1 2

2
*/

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

2204128
*/
