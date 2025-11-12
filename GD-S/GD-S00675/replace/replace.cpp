#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))
template<typename T> void chk_min(T &x, const T &y) { x = min(x, y); }
template<typename T> void chk_max(T &x, const T &y) { x = max(x, y); }
typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e5 + 5, M = 5e6 +5, B = 13331, MOD = 1e9 + 7;

inline int add(int x, int y) { return x += y, x >= MOD ? x - MOD : x; }
inline int sub(int x, int y) { return x -= y, x < 0 ? x + MOD : x; }
inline void cadd(int &x, int y) { (x += y) >= MOD && (x -= MOD); }
inline void csub(int &x, int y) { (x -= y) >= 0 || (x += MOD); }

int n, q, lim, tot, pw[N], ans[N];
int H1[N], H2[N];
int preh[M], sufh[M];
string s1[N], s2[N], pres[N], mids1[N], mids2[N], sufs[N];
string t1[N], t2[N], midt1[N], midt2[N], pret[N], suft[N];
map<pii, int> id;
vector<int> vs[N], vt[N];

inline int calc(const string &s) {
	int h = 0;
	for (char ch : s) h = add((ll)h * B % MOD, ch - 'a' + 1);
	return h;
}

/*
2 1
abcba adcda
xxxbcbxxx xxxdcdxxx
xxabcbaxx xxadcdaxx
1 1
abc abc
xxabcxx xxabcxx
*/

inline bool check(const string &s1, const string &s2, const string &t1, const string &t2) {
	if (t1.size() > s1.size() || t2.size() > s2.size()) return 0;
	bool ok1 = 1;
	if (t1.size()) ok1 &= s1.substr(s1.size() - t1.size()) == t1;
	bool ok2 = 1;
	if (t2.size()) ok2 &= s2.substr(0, t2.size()) == t2;
	return ok1 && ok2;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		int p = 0, len = s1[i].size();
		chk_max(lim, len);
		while (p < len && s1[i][p] == s2[i][p]) pres[i] += s1[i][p++];
		int q = len - 1;
		while (q > p && s1[i][q] == s2[i][q]) sufs[i] += s1[i][q--];
		reverse(sufs[i].begin(), sufs[i].end());
		for (int j = p; j <= q; ++j) mids1[i] += s1[i][j], mids2[i] += s2[i][j];
	}
	for (int i = 1; i <= q; ++i) {
		cin >> t1[i] >> t2[i];
		int p = 0, len = t1[i].size();
		chk_max(lim, len);
		while (p < len && t1[i][p] == t2[i][p]) pret[i] += t1[i][p++];
		int q = len - 1;
		while (q > p && t1[i][q] == t2[i][q]) suft[i] += t1[i][q--];
		reverse(suft[i].begin(), suft[i].end());
		for (int j = p; j <= q; ++j) midt1[i] += t1[i][j], midt2[i] += t2[i][j];
	}
	pw[0] = 1;
	for (int i = 1; i <= lim; ++i) pw[i] = (ll)pw[i - 1] * B % MOD;
	for (int i = 1; i <= n; ++i) {
		int h1 = calc(mids1[i]), h2 = calc(mids2[i]);
		H1[i] = calc(pres[i]), H2[i] = calc(sufs[i]);
		int num = id.count({h1, h2}) ? id[{h1, h2}] : (id[{h1, h2}] = ++tot);
		vs[num].push_back(i);
	}
	for (int i = 1; i <= q; ++i) {
		int h1 = calc(midt1[i]), h2 = calc(midt2[i]);
		int num = id.count({h1, h2}) ? id[{h1, h2}] : (id[{h1, h2}] = ++tot);
		vt[num].push_back(i);
	}
	for (int i = 1; i <= tot; ++i) if (!vs[i].empty() && !vt[i].empty()) {
		for (int num : vt[i]) {
//			cout << pres[1] << ' ' << sufs[1] << '\n';
//			preh[0] = 0;
//			for (int i = 0, len = pret[num].size(); i < len; ++i) preh[i + 1] = add(preh[i], (ll)pw[i] * (pret[num][len - 1 - i] - 'a' + 1) % MOD);
//			sufh[0] = 0;
//			for (int i = 0; i < suft[num].size(); ++i) sufh[i + 1] = add((ll)sufh[i] * B % MOD, suft[num][i] - 'a' + 1);
			int res = 0;
			for (int x : vs[i]) res += check(pret[num], suft[num], pres[x], sufs[x]);
//			for (int x : vs[i]) {
//				bool ok1 = (pres[x].size() <= pret[num].size() && preh[pres[x].size()] == H1[x]);
//				bool ok2 = (sufs[x].size() <= suft[num].size() && sufh[sufs[x].size()] == H2[x]);
//				res += ok1 && ok2;
//			}
			ans[num] = res;
		}
	}
	for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
	return 0;
} 
