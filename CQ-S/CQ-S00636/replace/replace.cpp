#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio (0), cin.tie (0), cout.tie (0)
#define res register int
//#define int long long
#define rep(i, l, r) for (res i = (l); i <= (r); i ++)
#define drep(i, l, r) for (res i = (r); i >= (l); i --)
#define tim clock () * 1.0 / CLOCKS_PER_SEC
#define PII pair <int, int>
#define iv inline void
#define siz(x) (int)x.size ()
#define all(x) x.begin (), x.end ()
#define pb push_back
using namespace std;
const int N = 200005;
iv cmin(int &x, int y) { x = x < y ? x : y; }
int n, m, tot;
string s[2][N];
map <string, map <string, int> > mp;
struct node { string l, r; };
vector <node> g[N];
map <string, bool> p2; int tot1;
map <string, int> h1[N];
vector <string> g1[N];
iv solve () {
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> s[0][i] >> s[1][i]; int sz = siz(s[0][i]);
		int l = 0, r = sz - 1;
		rep(j, 0, sz - 1) if (s[0][i][j] == s[1][i][j]) l ++; else break;
		drep(j, 0, sz - 1) if (s[0][i][j] == s[1][i][j]) r --; else break;
		if (l > r) continue; string ss1 = "", ss2 = "", tt1 = "", tt2 = "";
		rep(j, l, r) ss1 += s[0][i][j], ss2 += s[1][i][j];
		if (!mp[ss1][ss2]) mp[ss1][ss2] = ++ tot;
		drep(j, 0, l - 1) tt1 += s[0][i][j];
		rep(j, r + 1, sz - 1) tt2 += s[0][i][j];
		g[mp[ss1][ss2]].pb ({tt1, tt2});
		if (!h1[mp[ss1][ss2]][tt1]) h1[mp[ss1][ss2]][tt1] = ++ tot1;
		g1[h1[mp[ss1][ss2]][tt1]].pb (tt2);
	}
	rep(i, 1, m) {
		string t1, t2; cin >> t1 >> t2; int sz = siz(t1), ret = 0;
		if (siz(t1) != siz(t2)) { cout << 0 << '\n'; continue; }
		int l = 0, r = sz - 1;
		rep(j, 0, sz - 1) if (t1[j] == t2[j]) l ++; else break;
		drep(j, 0, sz - 1) if (t1[j] == t2[j]) r --; else break;
		string ss1 = "", ss2 = "", tt1 = "", tt2 = "";
		rep(j, l, r) ss1 += t1[j], ss2 += t2[j];
		if (!mp[ss1][ss2]) { cout << 0 << '\n'; continue; }
		int t = mp[ss1][ss2]; p2.clear ();
		rep(j, r + 1, sz - 1) p2[tt2] = 1, tt2 += t1[j]; p2[tt2] = 1;
		drep(j, 0, l - 1) {
			if (h1[t][tt1]) for (auto x : g1[h1[t][tt1]]) ret += p2[x];
			tt1 += t1[j];
		}
		if (h1[t][tt1]) for (auto x : g1[h1[t][tt1]]) ret += p2[x];
		cout << ret << '\n';
	}
}
signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	FASTIO;
	int T = 1; //cin >> T;
	while (T --) solve ();
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
