#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200010][3], t1, t2;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	while (q--)
	{
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		bool flag = false;
		int pos1, pos2, ans = 0;
		string ds1 = "", ds2 = "";
		for (int i = 0; i < t1.size(); i++)
		{
			if (t1[i] != t2[i])
			{
				pos1 = i;
				break;
			}
		}
		for (int i = t1.size() - 1; i >= 0; i--)
		{
			if (t1[i] != t2[i])
			{
				pos2 = i;
				break;
			}
		}
		int len = pos2 - pos1 + 1;
		ds1 = t1.substr(pos1, len);
		ds2 = t2.substr(pos1, len);
		for (int i = 1; i <= n; i++)
		{
			if (s[i][1].size() > t1.size()) continue;
			int sz = s[i][1].size();
			for (int j = 0; j <= sz - len && j <= pos1; j++)
			{
				if (s[i][1].substr(j, len) == ds1 && s[i][2].substr(j, len) == ds2)
				{
					if (t1.substr(pos1 - j, sz) == s[i][1] && t2.substr(pos1 - j, sz) == s[i][2])
					{
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

