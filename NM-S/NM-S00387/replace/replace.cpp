#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
#define ls cur << 1
#define rs cur << 1 | 1
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 2e5 + 100;
const int M = 1e6 + 10;
const int P = 998244353;
string s[N][2];
ull S[N][2];
ull H = 23323;
char t1[M], t2[M];
ull pre[M], pref[M], e[M];
ull PPP[M];
int main()
{
	ios ::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// 哈希没调出来 wuwuwu 
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	if(n >= 10000)
	{
		while(q --) cout << 0 << '\n';
		return 0;
	}
	rep(i, 1, n) cin >> s[i][0] >> s[i][1];
	rep(i, 1, n) rep(j, 0, 1)
		for(auto x : s[i][j])
			S[i][j] = S[i][j] * H + x;
	PPP[0] = 1;
	rep(i, 1, 1000000) PPP[i] = PPP[i - 1] * H;
	while(q --)
	{
		cin >> t1 + 1 >> t2 + 1;
		string tt1, tt2;
		tt1 += '[', tt2 += '[';
		int len = strlen(t1 + 1);
		rep(i, 1, len) tt1 += t1[i], tt2 += t2[i]; 
		ull hh = 1;
		repf(i, len, 1) e[i] = hh * t1[i], hh*=H;
		rep(i, 1, len) pre[i] = pre[i - 1] + e[i];
		repf(i, len, 1) pref[i] = pref[i + 1] + e[i];
		ull HHH = 0;
		int res = 0;
		rep(i, 1, len) HHH = HHH * H + t2[i];
		rep(i, 1, len)
		{
			rep(j, 1, n)
			{
				int en = s[j][0].size();
				if(en > i) continue;
				string sss;
				rep(k, i-en+1, i) sss += t1[k];
				string HP = tt1;
				if(sss == s[j][0]) 
				{
					int TT = 0;
					rep(k, i-en+1, i) HP[k] = s[j][1][TT++];
				}
				if(HP == tt2) res ++;
			}
		}
		cout << res << '\n';
	}
	return 0;
}
