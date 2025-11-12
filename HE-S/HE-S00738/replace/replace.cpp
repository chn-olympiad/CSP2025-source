#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n, q, ans;
map<string , string> mp;
string s, t, st, ts, ss, tt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(LL i = 1; i <= n; i++)
	{
		cin >> s >> t;
		mp[s] = t;
	}
	while(q--)
	{
		cin >> s >> t;
		ans = 0;
		if(s.size() != t.size())
		{
			cout << ans << endl;
			continue;
		}
		for(LL i = 0; i < s.size(); i++)
		{
			st = ts = "";
			ss = s;
			tt = t;
			for(LL j = i; j < s.size(); j++)
			{
				st += s[j];
				ts += t[j];
				ss[j] = tt[j];
				if(ss == tt && mp[st] == ts) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
