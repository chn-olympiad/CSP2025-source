#include <bits/stdc++.h>
#define uint unsigned long long

using namespace std;

int n, q;
string s[200010], t[200010];
unordered_map<string, int> mp;
struct node
{
	int id, l, r;
};
vector<node> g[200010];
int idx;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool ck = 0;
	for(int i = 1;i <= n;i ++)
	{
		string as, bs;
		cin >> as >> bs;
		if(ck == 0)
		{
			for(int j = 0;j < as.size();j ++)
			{
				if(as[j] > 'b' || bs[j] > 'b')
				{
					ck = 1;
					break;
				}
			}
		}
		int l = 0, r = as.size() - 1;
		for(;l < r;l ++) if(as[l] != bs[l]) break;
		for(;l < r;r --) if(as[r] != bs[r]) break;
		for(int j = l;j <= r;j ++) s[i] += as[j], t[i] += bs[j];
		string p = s[i] + t[i];
		s[i] = as, t[i] = bs;
		if(!mp.count(p)) mp[p] = ++ idx;
		g[mp[p]].push_back({i, l, (int)as.size() - r - 1});
	}
	for(int i = 1;i <= q;i ++)
	{
		string as, bs;
		cin >> as >> bs;
		if(ck == 0)
		{
			for(int j = 0;j < as.size();j ++)
			{
				if(as[j] > 'b' || bs[j] > 'b')
				{
					ck = 1;
					break;
				}
			}
		}
		int ans = 0;
		if(as.size() != bs.size())
		{
			cout << "0\n";
			continue;
		}
		int l = 0, r = as.size() - 1;
		for(;l < r;l ++) if(as[l] != bs[l]) break;
		for(;l < r;r --) if(as[r] != bs[r]) break;
		string tot;
		for(int j = l;j <= r;j ++) tot += as[j];
		for(int j = l;j <= r;j ++) tot += bs[j];
		if(!mp.count(tot)) cout << "0\n";
		else
		{
			int zb = mp[tot];
			for(auto i : g[zb])
			{
				if(l - i.l < 0 || r + i.r >= as.size()) continue;
				bool ok = 0;
				if(ck == 1)
				{
					for(int j = l - i.l, l = 0;j <= r + i.r;j ++, l ++)
					{
						if(as[j] != s[i.id][l] || bs[j] != t[i.id][l])
						{
							ok = 1;
							break;
						}
					}
				}
				if(ok == 0) ans ++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
