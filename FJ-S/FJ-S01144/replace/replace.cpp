#include <bits/stdc++.h>
using namespace std;
map<string, string> ma;
int n, m;
string makingstring(int l, int r, string ss)
{
	string s = "";
	for (int i = l; i <= r; i++)
		s += ss[i];
	return s;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;  i<= n; i++)
	{
		string s, ss;
		cin >> s >> ss;
		ma[s] = ss;
	}
	for (int i = 1; i <= m; i++)
	{
		string s, ss;
		cin >> s >> ss;
		int lenn = s.length();
		int l = 0, r = lenn - 1;
		for (; l < lenn; l++)
		{
			if (s[l] != ss[l])
				break;
		}
		for (; r >= 0; r--)
			if (s[r] != ss[r])
				break;
		int ans = 0;
		for (int j = l; j >= 0; j--)
		{
			for (int k = r; k < lenn; k++)
			{
				string mu = makingstring(j, k, s);
				string biao = makingstring(j, k, ss);
				if (ma[mu] == biao)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
