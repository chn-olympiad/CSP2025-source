//T3 = 10+15+5 = 30pts
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m;
string s[N], t[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == s2)
		{
			s[i] = s1;
			t[i] = s2;
			continue;
		}
		int len = s1.length();
		int k = 0;
		while(k < len)
		{
			if(s1[k] != s2[k]) break;
			k++;
		}
		int j = len - 1;
		while(i >= 0)
		{
			if(s1[j] != s2[j]) break;
			j--;
		}
		s[i] = s1.substr(k, j-k+1);
		t[i] = s2.substr(k, j-k+1);
	}
	while(m--)
	{
		string sx, sy;
		cin >> sx >> sy;
		int len = sx.length();
		int tmp = 0, tmp1 = 0;
		for(int i = 0; i < len; i++)
		{
			if(sx[i] != sy[i] && tmp1 == 0)
			{
				tmp ++;
				if(tmp > 1) break;
				tmp1 = 1;
			}
			if(sx[i] == sy[i]) tmp1 = 0;
		}
		// if(tmp > 1)
		// {
		// 	cout << "0\n";
		// 	continue;
		// }
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(sx == s[i])
			{
				if(t[i] == sy) ans++;
				continue;
			}
			size_t pl = sx.find(s[i]);
			if(pl == string::npos) continue;
			if(sx.substr(0, pl) + t[i] + sx.substr(pl + t[i].size(), 2) == sy.substr(0, pl + t[i].size()+2))
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
 } 
