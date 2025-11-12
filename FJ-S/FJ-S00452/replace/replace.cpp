#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 5;
map<string, string> mp;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	while(q--)
	{
		string t1, t2; cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		t1 = " " + t1;
		int ans = 0;
		for(int i = 1; i <= t1.size(); i++)
		{
			for(int j = 1; i + j <= t1.size(); j++)
			{
				string y = t1.substr(i, j);
				if(mp[y] == "") continue;
				y = mp[y];
				string x = t1.substr(1, i - 1);
				string z = t1.substr(i + j);
				string tmp = x + y + z;
				if(tmp == t2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
