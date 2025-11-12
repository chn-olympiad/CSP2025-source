#include<bits/stdc++.h>
using namespace std;

#define F(i, l, r) for(int i = (l); i <= (r); ++i)
#define dF(i, r, l) for(int i = (r); i >= (l); --i)
#define pb push_back
#define vi vector<int>

template<typename T> void debug(string s, T x) {
	cerr << "[ " << s << "] = [" << x << "]\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {
	int t = 0;
	F(i, 0, (int)s.size() - 1) if(s[i] =='(') t++;
	else if(s[i] == ')') t--;
	else if(s[i] == ',' && !t) {
		cerr << "[" << s.substr(0, i) << "] = [" << x << "] | ";
		debug(s.substr(s.find_first_not_of(' ', i + 1)), args...);
		break;
	}
}

#ifdef orzz
#define Debug(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define Debug(...) 
#endif

int ri() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' ||c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	} return x * f;
}

const int _ = 2e5 + 5;

#define fi first 
#define se second
#define pii pair<int, int>

bool Mbe;

int n, q, bel[_],cnt;

string s[_][2], s2[_][2], S[_], T[_];

const int M = 5e6 + 5;
const int Fk = 1474527, mod = 998244353;
const int Fk2 = 1527, mod2 = 1e9 + 7;
int Val[205];

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// struct Hash {
// 	int W1, W2;
// 	Hash() {
// 		W1= W2 = 0;
// 	}
	
// 	friend bool operator < (const Hash &a, const Hash &b) {
// 		return a.W1==b.W1 ? a.W1<b.W2:a.W1<b.W1;
// 	}
// 	friend bool operator == (const Hash &a, const Hash &b) {
// 		return a.W1==b.W1&&a.W2==b.W2;
// 	}
// };

void init(pii &a, string &s) {
	a.fi = a.se = 0;
	F(i, 0, (int)s.size() - 1) {
		a.fi = (1ll*a.fi*Fk%mod+Val[s[i]-'a']) % mod;
		a.se = (1ll*a.se*Fk2%mod2+Val[s[i]-'a'])%mod2;
	}
}

map<pair<pii, pii>, int> mp;

vi d[_]; vi qr[_];

int ans[_];

#define Try fprintf(stderr, "Time = %.4lf s\n", 1. * (clock()) / CLOCKS_PER_SEC)

vi g[M], g2[M];

int Slb[M], rt1, rt2;

struct trie {
	int tot, tr[M + 500][26];
	void clear() {
		F(i, 0, tot) {
			g[i].clear(), Slb[i] = 0;
			g2[i].clear();
			F(j, 0, 25) tr[i][j] = 0;
		}
		tot = 0;
	}
	int ins(int rt, string &s) {
		int len = s.size();
		int p = rt;
		F(i, 0, len - 1) {
			int t = s[i] - 'a';
			if(!tr[p][t]) tr[p][t] = ++tot;
			p = tr[p][t];
		} return p;
	}
	void dfs2(int u, int j, int z, int S) {
		// Debug("dfs2", u, j, z, T[z].size());
		S += Slb[u];
		if(j == T[z].size()) {
			// Debug(z, S);
			ans[z] += S;
			return;
		}
		// Debug(j, T[z][j], tr[u][T[z][j] - 'a']);
		assert(tr[u][T[z][j] - 'a']);
		dfs2(tr[u][T[z][j]-'a'], j+1, z, S);
	}
	void dfs1(int u) {
		for(int v : g[u]) Slb[v]++;
		for(int z : g2[u]) {
			// Debug("dfs2", u, z);
			dfs2(rt2, 0, z, 0);
		}
		F(j, 0, 25) if(tr[u][j]) {
			dfs1(tr[u][j]);
		}
		for(int v : g[u]) Slb[v]--;
	}
} A;

bool Mde;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w",stdout);
	fprintf(stderr, "%lf MB\n", 1.*(&Mbe - &Mde)/ 1024./1024.);
	// freopen("replace1.in", "r", stdin);
	F(i, 0, 105) Val[i] = rnd() % mod+1;
	n = ri(), q = ri();
	F(i,1, n) {
		cin >> s[i][0] >> s[i][1];
		if(s[i][0] == s[i][1]) continue;
		int len = s[i][0].size();
		int pre = -1, suf = len;
		F(j, 0, len - 1) if(s[i][0][j] == s[i][1][j]) {
			pre = j;
		} else break;
		dF(j, len - 1, 0) if(s[i][0][j] == s[i][1][j]) {
			suf = j;
		} else break;
		assert(pre < suf);
		pii b = {0, 0}, c = {0, 0};
		string Pre = "";
		F(j, 0, pre) Pre += s[i][0][j];
		::s2[i][0] = Pre;
		Pre = "";
		F(j, pre+1, suf - 1) {
			Pre += s[i][0][j];
		}
		init(b, Pre);
		Pre = "";
		F(j, pre+1, suf -1) {
			Pre += s[i][1][j];
		}
		init(c, Pre);
		Pre = "";
		F(j, suf, len - 1) {
			Pre += s[i][0][j];
		}
		::s2[i][1] = Pre;
		pair<pii, pii> A = make_pair(b, c);
		if(mp.find(A) == mp.end()) {
			mp[A] = ++cnt;
		}
		bel[i] = mp[A];
		::d[bel[i]].pb(i);
	}
	F(z, 1, q) {
		string S, T;
		cin >> S >> T;
		int lS = S.size(), lT = T.size();
		if(lS != lT) {
			ans[z] = 0;
			continue;
		}
		vi id;
		int pre = -1, suf = lS;
		F(j, 0, lS - 1) if(S[j] == T[j]) {
			pre = j;
		} else break;
		dF(j, lS - 1, 0) if(S[j] == T[j]) {
			suf = j;
		} else break;
		pii b, c;
		{
			string Pre = "";
			F(j, pre+1, suf - 1) {
				Pre += S[j];
			}
			init(b, Pre);
			Pre = "";
			F(j, pre + 1, suf -1) {
				Pre += T[j];
			}
			init(c, Pre);
		}
		pair<pii, pii> A = make_pair(b, c);
		if(mp.find(A) == mp.end()) {
			continue;
		}
		// assert(mp[A] >=1&& mp[A] <=cnt && !d[mp[A]].empty());
		qr[mp[A]].pb(z);
		F(i, 0, pre) ::S[z] += S[i];
		F(i, suf, lS - 1) ::T[z] += S[i];
	}
	Debug(cnt);
	F(i, 1, cnt) {
		if(d[i].empty() || qr[i].empty()) continue;
		A.clear();
		rt1 = ++A.tot, rt2 = ++A.tot;
		for(int j : d[i]) {
			reverse(s2[j][0].begin(),s2[j][0].end());
			int p = A.ins(rt1, s2[j][0]);
			int q = A.ins(rt2, s2[j][1]);
			g[p].pb(q);
			// Debug(i, j);
		}
		for(int z : qr[i]) {
			reverse(S[z].begin(), S[z].end());
			int p = A.ins(rt1, S[z]);
			int q = A.ins(rt2, T[z]);
			g2[p].pb(z);
			// Debug(i, z);
		}
		A.dfs1(rt1);
		// for(int z : qr[i]) {
		// 	for(int j : d[i]) {
		// 		// Debug(z, j);
		// 		auto chk2 = [&](string s1, string s2) -> bool {
		// 			if(s2.size() < s1.size()) return 0;
		// 			F(i, 0, (int)s1.size() -1) if(s1[i] != s2[i]) return 0;
		// 			return 1;
		// 		};
		// 		auto chk1 = [&](string s1, string s2) -> bool {
		// 			reverse(s1.begin(), s1.end());
		// 			reverse(s2.begin(), s2.end());
		// 			return chk2(s1, s2);
		// 		};
		// 		if(chk1(s2[j][0], S[z]) && chk2(s2[j][1], T[z])) {
		// 			ans[z]++;
		// 		}
		// 	}
		// }
		// assert(!d[i].empty());
	}
	F(i, 1, q) printf("%d\n", ans[i]);
	Try;
}