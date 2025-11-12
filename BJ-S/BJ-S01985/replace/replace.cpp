#include <iostream>
using namespace std;

const int N = 100010;
string s[N][2];

string subs(string s, int b, int l)
{
	string ans = "";
	for (int i = b; i < b + l; i++)
	{
		ans += s[i];
	}
	return ans;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
	}
	int ans = 0;
	string s1, s2;
	for (int i = 1; i <= m; i++)
	{
		cin >> s1 >> s2;
		ans = 0;
		for (int j = 0; j <= s1.length() - s[i][0].length(); j++)
		{
			if (subs(s1, j, s[i][0].length()) == s[i][0])
			{
				if (subs(s2, j, s[i][0].length()) == s[i][1])
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}