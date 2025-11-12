#include <bits/stdc++.h>
using namespace std;
int n, m, tot = 0;
string s1, s2;
map <string, int> mp;
vector <string> g[200006];
int SolveB()
{
	//LEC:NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> s1 >> s2;
		if (mp[s1]) g[mp[s1]].push_back(s2);
		else mp[s1] = ++tot, g[tot].push_back(s2);
	}
	while (m--)
	{
		cin >> s1 >> s2; int ans = 0;
		for (int l = 0; l < s1.size(); l++)
			for (int r = l; r < s1.size(); r++)
			{
				for (string t : g[mp[s1.substr(l, r - l + 1)]])
					if (s1.substr(0, l) + t + s1.substr(r + 1) == s2) ans++;
			}
		cout << ans << endl;
	}
	return 0;
}
