#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define ms(a,b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define mk make_pair


inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch >'9' || ch < '0')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x*f;
}

int n, q;
string s[200010][2];
map<string,vector<string> > f;
string t1, t2;

inline int check(string t, string _t, int l, int r, int j)
{
	for(int i = 1;i <= j;++i)
	{
		t += t1[r+i];
		_t += t2[r+i];
	}
	if(!f.count(t)) return 0;
	if(f[t].empty()) return 0;
	for(auto _s : f[t])
	{
		if(_s == _t) return 1;
	}
	return 0;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(), q = read();
	for(int i = 1;i <= n;++i)
	{
		cin >> s[i][0] >> s[i][1];
//		scanf("%lls%lls",&s[i][0],&s[i][1]);
		f[s[i][0]].pb(s[i][1]);
	}
	while(q--)
	{
		cin >> t1 >> t2;
//		scanf("%lls%lls",&t1,&t2);
		if(t1.size() != t2.size())
		{
			puts("0");
			continue;
		}
		int l = 0, r = t1.size()-1;
		while(t1[l] == t2[l]) ++l;
		while(t1[r] == t2[r]) --r;
		string t = "", _t = "";
		for(int i = l;i <= r;++i) t += t1[i], _t += t2[i];
		int ans = 0;
		for(int i = 0;i <= l;++i)
		{
			if(i) t = t1[l-i]+t, _t = t2[l-i]+_t;
			for(int j = 0;j <= t1.size()-1-r;++j) ans += (check(t,_t,l,r,j));
		}
		cout << ans << endl;
	}
	return 0;
}
