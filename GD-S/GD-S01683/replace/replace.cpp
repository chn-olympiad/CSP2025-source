#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;

unordered_map <string, string> rpy;

int que(string t1, string t2)
{
	int ret = 0;
	
	for (auto i = rpy.begin(); i != rpy.end(); ++i)
	{
		if (t1.find(i -> first) != string::npos)
		{
			string t3 = t1;
			string riy = i -> second;
			int pos = t1.find(i -> first);
			for (char ch : riy)
			{
				t3[pos] = ch;
				++pos;
			}
			if (t3 == t2)++ret;
		}
	}
	
	return ret;
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		rpy[s1] = s2;
	}
	
	for (int i = 1; i <= q; ++i)
	{
		string t1, t2;
		cin >> t1 >> t2;
		cout << que(t1, t2) << "\n";
	}
	return 0;
}
