#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, cnt, pi[N], pos[N];
string s[N][2], t[2];
void get_pi(string s)
{
	for(int i = 1;i < s.size();i++)
	{
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j]) j = pi[j - 1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> s[i][0] >> s[i][1];
	if(q >= 1000)
	{
		for(int i = 1;i <= q;i++) cout << "0\n";
		return 0; 
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size())
		{
			cout << "0\n";
			continue;
		}
		int ans = 0;
		for(int j = 1;j <= n;j++)
		{
			if(s[j][0].size() > t[0].size()) continue;
			cnt = 0;
			string tmp = s[j][0] + "#" + t[0];
			get_pi(tmp);
			for(int k = s[j][0].size() + 1;k < tmp.size();k++)
				if(pi[k] == s[j][0].size())
					pos[++cnt] = k - 2 * s[j][0].size();
			tmp = s[j][1] + "#" + t[1];
			get_pi(tmp);
			for(int k = s[j][1].size() + 1;k < tmp.size();k++)
				if(pi[k] == s[j][1].size())
				{
					int o = lower_bound(pos + 1, pos + cnt + 1, k - 2 * s[j][1].size()) - pos;
					int v = *lower_bound(pos + 1, pos + cnt + 1, k - 2 * s[j][1].size());
					cout << v << " " << pos[o] << "\n";
					if(v == pos[o])
					{
						string ca = t[0].substr(0, v);
						string cb = t[1].substr(0, v);
						if(ca != cb) continue;
						string da = t[0].substr(v + s[j][1].size());
						string db = t[1].substr(v + s[j][1].size());
						if(da != db) continue;
						ans++;
					}
				}
		}	
		cout << ans << "\n";
	}
	return 0;
}
