#include<bits/stdc++.h>
using namespace std;

unordered_map <string, string> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] += s2;
	}
	while (q--)
	{
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		int sz = t2.size();
		for (register int lenl = 0; lenl < sz; lenl++)
		{
			for (register int lenr = 0; lenl + lenr < sz; lenr++)
			{
				string l = t1.substr(0, lenl);
				string ll = t2.substr(0, lenl);
				if (l != ll) continue;
				string r = t1.substr(sz - lenr, lenr);
				string rr = t2.substr(sz - lenr, lenr);
				if (r != rr) continue;
				string mid1 = t1.substr(lenl, sz - lenl - lenr);
				string mid2 = t2.substr(lenl, sz - lenl - lenr);
				int md1 = mp[mid1].size(), mdt = mid1.size();
				for (int i = 0; i < md1; i += mdt)
				{
					string k = mp[mid1].substr(i, mdt);
					if (k == mid2) ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
