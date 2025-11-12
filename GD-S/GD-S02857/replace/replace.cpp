#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,base1 = 37,base2 = 31,mod1 = 1e9+7,mod2 = 1e7+9,tot,st[200005],ed[200005],hash1[200005],hash2[200005];
int hash3[200005],hash4[200005];
string s[200005][5],t[200005][5];
map<pair<pair<int,int>,pair<int,int>>,vector<int>> to;
vector<string> spe;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
		st[i] = -1;
		for(int j = 0; j < s[i][1].size(); j++)
		{
			hash1[i] = (hash1[i]*base1+s[i][1][j]-'a')%mod1;
			hash2[i] = (hash2[i]*base2+s[i][1][j]-'a')%mod2;
			hash3[i] = (hash3[i]*base1+s[i][2][j]-'a')%mod1;
			hash4[i] = (hash4[i]*base2+s[i][2][j]-'a')%mod2;
			if(s[i][1][j] == s[i][2][j]) continue;
			else
			{
//				cout << i << " " << j << endl;
				if(st[i] == -1) st[i] = j;
				ed[i] = j;
			}
		}
		if(st[i] == -1)
		{
			spe.push_back(s[i][1]);
			continue;
		}
		int hash11 = 0,hash21 = 0,hash12 = 0,hash22 = 0;
//		cout << st[i] << " " << ed[i] << endl;
		for(int j = st[i]; j <= ed[i]; j++)
		{
			hash11 = (hash11*base1+s[i][1][j]-'a')%mod1;
			hash21 = (hash21*base2+s[i][1][j]-'a')%mod2;
			hash12 = (hash12*base1+s[i][2][j]-'a')%mod1;
			hash22 = (hash22*base2+s[i][2][j]-'a')%mod2;
		}
//		cout << hash11 << " " << hash21 << " " << hash12 << " " << hash22 << endl;
		to[{{hash11,hash21},{hash12,hash22}}].push_back(i);
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> t[i][1] >> t[i][2];
		int stt = -1,edt = 0;
		for(int j = 0; j < t[i][1].size(); j++)
		{
			if(t[i][1][j] == t[i][2][j]) continue;
			else
			{
				if(stt == -1) stt = j;
				edt = j;
			}
		}
		if(stt == -1)
		{
			int res = 0;
			for(int i = 0; i < spe.size(); i++)
			{
				if(t[i][1].find(spe[i]) < t[i][1].size()) res++;
			}
			cout << res+1 << endl;
			continue;
		}
		int hash11 = 0,hash21 = 0,hash12 = 0,hash22 = 0;
		for(int j = stt; j <= edt; j++)
		{
			hash11 = (hash11*base1+t[i][1][j]-'a')%mod1;
			hash21 = (hash21*base2+t[i][1][j]-'a')%mod2;
			hash12 = (hash12*base1+t[i][2][j]-'a')%mod1;
			hash22 = (hash22*base2+t[i][2][j]-'a')%mod2;
		}
		int ans = 0;
//		cout << stt << " " << edt << endl;
		for(int j = 0; j < to[{{hash11,hash21},{hash12,hash22}}].size(); j++)
		{
			int x = to[{{hash11,hash21},{hash12,hash22}}][j];
//			cout << i << ":" << x << endl;
			int h1 = 0,h2 = 0,h3 = 0,h4 = 0;
//			cout << stt-st[x] << " to " << edt+s[x][1].size()-ed[x]-1 << endl;
			for(int k = max(stt-st[x],0ll); k <= min(edt+s[x][1].size()-ed[x]-1,t[i][1].size()-1); k++)
			{
				h1 = (h1*base1+t[i][1][k]-'a')%mod1;
				h2 = (h2*base2+t[i][1][k]-'a')%mod2;
				h3 = (h3*base1+t[i][2][k]-'a')%mod1;
				h4 = (h4*base2+t[i][2][k]-'a')%mod2;
			}
			if(h1 == hash1[x] && h2 == hash2[x] && h3 == hash3[x] && h4 == hash4[x]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
