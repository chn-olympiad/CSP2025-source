#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define lb(x) (x&-x)

namespace rsy {
using namespace std;
using i64 = long long;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
void chmax (int &x, int c) { x = max(x, c); }
void chmin (int &x, int c) { x = min(x, c); }

const int maxn = 5e6 + 10;
int len, pw[maxn], pS[maxn], pT[maxn];
const int B = 97ll, mod = 998244853;
void init(string S, string T) {
	for (int i = 1; i <= len; i++)
		pS[i] = (1ll * pS[i - 1] * B % mod + S[i] - 'a' + 1) % mod,
		pT[i] = (1ll * pT[i - 1] * B % mod + T[i] - 'a' + 1) % mod;
}
int getS (int l, int r) { return (pS[r] - 1ll * pS[l - 1] * pw[r - l + 1] % mod + mod) % mod; }
int getT (int l, int r) { return (pT[r] - 1ll * pT[l - 1] * pw[r - l + 1] % mod + mod) % mod; }
int N, Q, tot = 0;

// 从 x->y，后缀相同长度 <= t 
const int inf = 1e9;
ll get(int x, int y) { return 1ll * x * inf + y; }
unordered_map<ll, int> mp;
struct qwq { int ps, pt, w; } e[maxn];
vector<int> g[maxn];
int query (int x, int k) {
	if (g[x][0] > k) return 0;
	if (g[x][g[x].size() - 1] <= k) return g[x].size();
	return upper_bound(g[x].begin(), g[x].end(), k) - g[x].begin();
}
int query (int x, int y, int t) {
	int Pos = mp[get(x, y)];
	if (!Pos) return 0;
	return query(Pos, t);
}

namespace baoli {
	
	void main() {
		L (i, 1, N) {
			string S, T;
			cin >> S >> T;
			len = S.size(), S = ' ' + S, T = ' ' + T, init(S, T);
			mp[get(pS[len], pT[len])]++;
		}
		L (x, 1, Q) {
			string S, T;
			cin >> S >> T, S = ' ' + S, T = ' ' + T;
			if (S.size() != T.size()) { cout << 0 << '\n'; continue; }
			len = S.size() - 1, init(S, T);
			int l = 0, r = len + 1;
			L (i, 1, len) if (S[i] == T[i]) l = i; else break;
			R (i, len, 1) if (S[i] == T[i]) r = i; else break;
			ll res = 0;
			L (i, 1, l + 1) L (j, r - 1, len) res += mp[get(getS(i, j), getT(i, j))];
			cout << res << '\n';
		}
	}
}

void solve() {
	cin >> N >> Q;
	if (N <= 1000 && Q <= 1000) return baoli::main();
	int eid = 0;
	L (i, 1, N) {
		string S, T;
		cin >> S >> T;
		len = S.size(), S = ' ' + S, T = ' ' + T, init(S, T);
		int lst = len + 1;
		R (i, len, 1) if (S[i] == T[i]) lst = i; else break;
		L (i, 0, len - lst + 1) e[++eid] = {pS[len - i], pT[len - i], i};
	}
	L (i, 1, eid) if (!mp[get(e[i].ps, e[i].pt)]) mp[get(e[i].ps, e[i].pt)] = ++tot;
	L (i, 1, eid) g[mp[get(e[i].ps, e[i].pt)]].push_back(e[i].w);
	L (i, 1, tot) sort (g[i].begin(), g[i].end());
	L (x, 1, Q) {
		string S, T;
		cin >> S >> T, S = ' ' + S, T = ' ' + T;
		if (S.size() != T.size()) { cout << 0 << '\n'; continue; }
		len = S.size() - 1, init(S, T);
		int l = 0, r = len + 1;
		L (i, 1, len) if (S[i] == T[i]) l = i; else break;
		R (i, len, 1) if (S[i] == T[i]) r = i; else break;
		ll res = 0;
		L (i, 0, l) {
			int ql = i + 1, qr = r - 1;
			res += query(getS(ql, qr), getT(ql, qr), len - r + 1);
		}
		cout << res << '\n';
	}
}

signed main() {
	pw[0] = 1; L (i, 1, maxn - 10) pw[i] = 1ll * pw[i - 1] * B % mod;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
} signed main() {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	return rsy::main();
}
// 316MB
