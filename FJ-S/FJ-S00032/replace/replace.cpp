#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, q, posb1[N], posb2[N];
string s[N], t1, t2;
unordered_map<string, string> mp;
void bl()
{
	for(int i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			puts("0");
			continue;
		}
		string trep;
		trep = t1;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int pos = trep.find(s[i]);
			if(pos < trep.size())trep.replace(pos, s[i].size(), mp[s[i]]);
			if(trep == t2)ans++;
			trep = t1;
		}
		printf("%d\n", ans);
	}
}
void ts()
{
	int posbt1 = 0, posbt2 = 0, ans = 0;
	for(int i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		for(int j = 0; j <= t1.size(); j++)
		{
			if(t1[i] == 'b')posbt1 = j;
			break;
		}
		for(int j = 0; j <= t2.size(); j++)
		{
			if(t2[i] == 'b')posbt2 = j;
			break;
		}
		for(int i = 1; i <= n; i++)
		{
			if(t1.size() < s[i].size())continue;
			int _ = posb2[i] - posb1[i];
			int tmp = posbt1;
			tmp += _;
			cout << tmp << ' ' << posbt2 << endl;
			if(tmp == posbt2)ans++;
		}
	}
	printf("%d\n", ans);
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		s[i] = s1;
		for(int j = 0; j < s1.size(); j++) if(s1[j] == 'b'){posb1[i] = j;break;}
		for(int j = 0; j < s2.size(); j++) if(s2[j] == 'b'){posb2[i] = j;break;}
		mp[s1] = s2;
	}
	if(n <= 1000 && q <= 1000 || q == 1)
	{
		bl();
	}
	else
	{
		ts();
	}
	return 0;
}
/*
2 1
aabaa abaaa
ab ba
aaabaaa aabaaaa
*/
