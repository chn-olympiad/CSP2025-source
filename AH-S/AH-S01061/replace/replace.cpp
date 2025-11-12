#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[200005], s2[200005], t1, t2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while (q--)
	{
		int ans = 0;
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++)
		{
			string sum = "";
			for (int j = 0; j < s1[i].size(); j++)
			{
				sum += t1[j];
			}
			string tmp = t1;
			if (sum == s1[i] && tmp.replace(0, s1[i].size(), sum) == t2)
			{
				ans++;
				continue;
			}
			for (int j = 1; j + s1[i].size() - 1 < t1.size(); j++)
			{
				tmp = t1;
				for (int k = j + 1; k < j + s1[i].length() - 1; k++)
				{
					sum += t1[k];
				}
				if (sum == s1[i] && tmp.replace(j, s1[i].size(), sum) == t2)
				{
					ans++;
					break;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
