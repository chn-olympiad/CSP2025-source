#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, q;
pair<string, string> s[200005];
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		s[i] = {s1, s2};
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		int n1 = t1.length(), n2 = t2.length();
		if (n1 != n2)
		{
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			string s1 = s[i].first, s2 = s[i].second;
			int l = s1.length();
			bool is = true;
			for (int L = 0, R = l - 1; R < n1; L++, R++)
			{
				string t3 = t1;
				is = true;
				for (int kkk = L; kkk <= R; kkk++)
				{
					if (s1[kkk - L] != t1[kkk])
					{
						is = false;
						break;
					}
				}
				if (!is) continue;
				for (int kkk = L; kkk <= R; kkk++)
					t3[kkk] = s2[kkk - L];
				if (t3 == t2)
				{
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
