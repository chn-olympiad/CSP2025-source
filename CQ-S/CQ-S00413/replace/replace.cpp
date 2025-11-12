#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define ull unsigned ll
inline void Fin(string s) { freopen((s + ".in").c_str(), "r", stdin); }
inline void Fout(string s) { freopen((s + ".out").c_str(), "w", stdout); }
const int B1 = 131;
const int M = 5000005, N = 200020, V = 300;
ull f1[M];
int n, m, len1[N], len2[N], idx, p1[N], p2[N], l[N], r[N];
string s[N], t[N], a[N], b[N];
ull v1[N], v2[N]; int ans[N];
map<pair<ull, ull>, int> mp;
vector<ull> h2[N];
inline int gid(const ull &x, const ull &y) {
	int &o = mp[{x, y}];
	if(!o) o = ++idx; return o;
}
vector<int> P[N * 2], Q[N * 2];
int main() {
	Fin("replace"), Fout("replace");
	fastio; 
	f1[0] = 1; rep(i, 1, M - 1) f1[i] = f1[i - 1] * B1;
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> s[i] >> t[i];
		len1[i] = s[i].size();
		int p = 0, q = len1[i] - 1;
		while(s[i][p] == t[i][p]) ++p;
		while(t[i][q] == s[i][q]) --q;
		ull w1 = 0, w2 = 0;
		rep(j, p, q) w1 = w1 * B1 + s[i][j], w2 = w2 * B1 + t[i][j];
		P[gid(w1, w2)].pb(i);
		p1[i] = p, p2[i] = len1[i] - q - 1;
		w1 = 0;
		rep(j, 0, p - 1) w1 = w1 * B1 + s[i][j];
		v1[i] = w1;
		w1 = 0;
		rep(j, q + 1, len1[i] - 1) w1 = w1 * B1 + s[i][j];
		v2[i] = w1;
	}
	rep(i, 1, m) {
		cin >> a[i] >> b[i];
		len2[i] = a[i].size();
		int p = 0, q = len2[i] - 1;
		while(a[i][p] == b[i][p]) ++p;
		while(a[i][q] == b[i][q]) q--;
		ull w1 = 0, w2 = 0;
		rep(j, p, q) w1 = w1 * B1 + a[i][j], w2 = w2 * B1 + b[i][j];
		Q[gid(w1, w2)].pb(i);
		l[i] = p, r[i] = q;
		h2[i].resize(len2[i] + 1);
		rep(j, 1, len2[i]) h2[i][j] = h2[i][j - 1] * B1 + a[i][j - 1];
	}
	rep(o, 1, idx) {
		if(!P[o].size() || !Q[o].size()) continue;
		if(P[o].size() <= V || Q[o].size() <= V) {
			for(int x : P[o]) for(const int &y : Q[o]) {
				if(p1[x] > l[y] || p2[x] > len2[y] - r[y] - 1) continue;
				ans[y] += (h2[y][l[y]] - h2[y][l[y] - p1[x]] * f1[p1[x]] == v1[x]) && (h2[y][r[y] + p2[x] + 1] - h2[y][r[y] + 1] * f1[p2[x]] == v2[x]);
			}
		} else {
//			assert(0);
			int L = 10;
			map<ull, vector<int> > m1, m2;
			vector<int> BL;
			for(int x : P[o]) if(p1[x] <= L && p2[x] <= L) m1[v1[x]].pb(x); else BL.pb(x);
			for(const int &y : Q[o]) {
				rep(i, 0, min(l[y], L)) {
					ull va = h2[y][l[y]] - h2[y][l[y] - i] * f1[i];
					if(m1.find(va) != m1.end()) m2[va].pb(y); 
				}
			}
			for(auto u : m1) {
				unordered_map<ull, int> mp;
				for(int v : u.se) mp[v2[v]]++;
				vector<int> &ve = m2[u.fi];
				for(int y : ve) {
					rep(j, 0, min(len2[y] - r[y] - 1, L)) {
						ull v = h2[y][r[y] + j + 1] - h2[y][r[y] + 1] * f1[j];
						auto p = mp.find(v);
						if(p != mp.end()) ans[y] += p -> se;
					}
				}
			}
//			cerr << P[o].size() << ' ' << Q[o].size() << ' ' << BL.size() << '\n';
			for(int x : BL) for(const int &y : Q[o]) {
				if(p1[x] > l[y] || p2[x] > len2[y] - r[y] - 1) continue;
				ans[y] += (h2[y][l[y]] - h2[y][l[y] - p1[x]] * f1[p1[x]] == v1[x]) && (h2[y][r[y] + p2[x] + 1] - h2[y][r[y] + 1] * f1[p2[x]] == v2[x]);
			}
		}
	}
	rep(i, 1, m) cout << ans[i] << '\n';
	return 0;
}

