//orz baokun
#include <iostream>
#include <string>
#include <map>
using namespace std;
int n, q, ans;
string s1, s2, t1, t2;
map<string, string> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	for (int i = 1; i <= q; i++)
	{
		ans = 0;
		cin >> t1 >> t2;
		string cpy = t1;
		int sz = t1.size(), sz2 = t2.size();
		if (sz != sz2)
		{
			cout << "0\n";
			continue;
		}
		for (int l = 0; l < sz; l++)
		{
			for(pair<string, string> i : mp)
			{
				int s = i.first.size();
				if (t1.substr(l, s) == i.first && t2.substr(l, s) == i.second)
				{
					for (int j = l; j <= l + s - 1; j++)
						t1[j] = i.second[j - l];
					if (t1 == t2)
						ans++;
					t1 = cpy;
				}
			}
		}
		cout << ans << '\n';
	}
}
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
