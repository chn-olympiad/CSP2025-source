#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define Max ((int) (1e5 + 5))

using namespace std;

int n, q;
map<string, string> mp; 

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string s, t;
		cin >> s >> t;
		mp[s] = t;
	}
	while (q--)
	{
		int ans = 0;
		string s, t;
		cin >> s >> t;
		for (int i = 1; i <= n; i++)
		{
			for (int len = 1; i + len - 1 <= n; len++)
			{
				string str1, str2;
				str1 = s.substr(i, len);
				str2 = t.substr(i, len);
				if (mp[str1] == str2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

