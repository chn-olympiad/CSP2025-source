#include<bits/stdc++.h>
using namespace std;

int n, q;

string s[1007], ss[1007], y[1007];

map <string, string> mp;

signed main()
{
	freopen("replace.in" ,"r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i] >> ss[i];
		mp[s[i]] = ss[i];
	}
	
	if(q > 1000)
	{
		while(q--)
			puts("0");
		return 0;
	}
	
	while(q--)
	{
		string t, tt;
		cin >> t >> tt;
		long long ans = 0;
		if(mp[t] != "")
		{
			if(mp[t] == tt)
				++ans;
		}
		y[t.size()] = "";
		for(int i = t.size() - 1; i >= 0; i--)
			y[i] = t[i] + y[i + 1];
		string x = "";
		for(int i = 0; i < t.size(); i++)
		{
			x += t[i];
			string now = "";
			for(int j = i + 1; j < t.size(); j++)
			{
				now += t[j];
				if(mp[now] != "")
				{
					string res = x + mp[now] + y[j + 1];
					if(res == tt)
						++ans;
				}
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
