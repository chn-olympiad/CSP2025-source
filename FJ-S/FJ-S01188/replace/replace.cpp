# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s[2][N];
int ans;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[0][i] >> s[1][i];
	}
	while (q --)
	{
		ans = 0;
		string str1, str2;
		cin >> str1 >> str2;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 0; j < (int)str1.size() - (int)s[0][i].size() + 1; j ++)
			{
				if (str1.substr(j, s[0][i].size()) == s[0][i] && (str1.substr(0, j) + s[1][i] + str1.substr(j + s[0][i].size())) == str2)
				{
					ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

