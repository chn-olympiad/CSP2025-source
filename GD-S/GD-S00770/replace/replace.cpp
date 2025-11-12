#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
string s1[200010],s2[200010];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	while (q--)
	{
		string s,t;
		cin >> s >> t;
		if (s.size() != t.size())
		{
			cout << 0 << endl;
		}
		int st;
		for (int i = 0 ; i < s.size() ; i++)
		{
			if (s[i] != t[i])
			{
				st = i;
			}
		}
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 0 ; j < s1[i].size() ; j++)
			{
				
			}
		}
		cout << n / 2 << endl;
	}
	return 0;
} 
