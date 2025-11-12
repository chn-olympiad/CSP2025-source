//No one cares you else yourself.
#include<bits/stdc++.h>
using namespace std;
map<string, string> mp;
//×ó¶Ë+ÓÒ¶Ë£¬Ë«±Õ 
string get_string(string s, int l, int r)
{
	string res;
	for (int i = l; i <= r; i++)
	{
		res += s[i];
	}
	return res;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	} 
	while (m--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int ans = 0;
		for (int len = 1; len <= s1.length(); len++)
		{
			for (int i = 0; i + len - 1 < s1.length(); i++)
			{
				for (int j = 0; j + len - 1 < s1.length(); j++)
				{
					string ss = get_string(s1, i, i + len - 1);
					string lyh = get_string(s2, j, j + len - 1);
					string yc = get_string(s1, 0, i - 1);
					string YC = get_string(s1, i + len, s1.length() - 1);
					if (mp[ss] == lyh)
					{
						string news = yc + lyh + YC;
						if (news == s2)
						{
							ans++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
