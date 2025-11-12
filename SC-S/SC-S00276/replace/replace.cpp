#include <bits/stdc++.h>

using namespace std;

typedef long long lnt;

const int N = 2e5 + 7, M = 5e6 + 7;

template<int M, int B>
struct has {
	int x;
	
	inline void add(int y) {
		x = ((lnt) x * B + y) % M;
	}
	
	inline bool operator< (const has<M, B> o) const {
		return x < o.x;
	}
	
	inline bool operator== (const has<M, B> o) const {
		return x == o.x;
	}
};

typedef has<1000000087, 100313> ha1;
typedef has<998244853 , 100847> ha2;

int n, m;

struct Str {
	string L, R;
	ha1 A1, B1;
	ha2 A2, B2;
	
	inline bool in() {
		string s, t;
		cin >> s >> t;
		if (s == t) {
			return false;
		}
		int le = s.size();
		int l = 0;
		while (s[l] == t[l]) {
			++ l;
		}
		int r = le;
		while (s[r - 1] == t[r - 1]) {
			-- r;
		}
		L = s.substr(0, l);
		R = s.substr(r);
		reverse(L.begin(), L.end());
		for (int i = l; i < r; ++ i) {
			A1.add(s[i]);
			A2.add(s[i]);
			B1.add(t[i]);
			B2.add(t[i]);
		}
		return true;
	}
	
	inline bool operator< (const Str o) const {
		return A1 == o.A1 ? (B1 == o.B1 ? (A2 == o.A2 ? B2 < o.B2 : A2 < o.A2) : B1 < o.B1) : A1 < o.A1;
	}
	
	inline bool operator== (const Str o) const {
		return A1 == o.A1 && B1 == o.B1 && A2 == o.A2 && B2 == o.B2;
	}
} a[N], b[N];

struct ACAM {
	int tri[M][26];
	int fai[M];
	int cnt;
	int dfn[M];
	int dnt;
	int siz[M];
	
	inline void clear() {
		memset(tri, 0, (cnt + 1) * sizeof(tri[0]));
		memset(fai, 0, (cnt + 1) * sizeof(fai[0]));
		cnt = 0;
		dnt = 0;
	}
	
	inline int ins(string s) {
		int u = 0;
		for (auto c : s) {
			int &v = u[tri][c - 'a'];
			if (v == 0) {
				v = ++ cnt;
			}
			u = v;
		}
		return u;
	}
	
	void dfs(int u) {
		u[dfn] = ++ dnt;
		u[siz] = 1;
		for (int j = 0; j < 26; ++ j) {
			if (u[tri][j]) {
				dfs(u[tri][j]);
				u[siz] += u[tri][j][siz];
			}
		}
	}
	
	inline int walk(string s) {
		int u = 0;
		for (auto c : s) {
			if (u[tri][c - 'a']) {
				u = u[tri][c - 'a'];
			} else {
				return u;
			}
		}
		return u;
	}
} acl, acr;

int ia[N];
int ib[N];

int ax[N];
int ay[N];

struct Qt {
	int x, l, r;
	int op, v;
};

vector<Qt> Q;

struct SS {
	int n;
	
	int ss[M];
	
	inline void add(int x, int v) {
		for (; x <= n; x += x & -x) {
			ss[x] += v;
		}
	}
	
	inline int sum(int x) {
		int res = 0;
		for (; x; x -= x & -x) {
			res += ss[x];
		}
		return res;
	}
	
	inline void clear() {
		memset(ss, 0, (n + 1) * sizeof(ss[0]));
	}
} ss;

void clear() {
	acl.clear();
	acr.clear();
	Q.clear();
	ss.clear();
}

int ans[N];

void INIT() { }

void WORK() {
	cin >> n >> m;
	int nt = n;
	n = 1;
	for (; nt; -- nt) {
		if (a[n].in()) {
			ia[n] = n;
			++ n;
		}
	}
	-- n;
	for (int i = 1; i <= m; ++ i) {
		b[i].in();
		ib[i] = i;
	}
	sort(ia + 1, ia + n + 1, [&](int i, int j) {
		return a[i] < a[j];
	});
	sort(ib + 1, ib + m + 1, [&](int i, int j) {
		return b[i] < b[j];
	});
	for (int L = 1, R, i = 1; L <= m && i <= n; ) {
		for (R = L + 1; R <= m && b[ib[L]] == b[ib[R]]; ) {
			++ R;
		}
		while (i <= n && a[ia[i]] < b[ib[L]]) {
			++ i;
		}
		if (i > n || !(a[ia[i]] == b[ib[L]])) {
			L = R;
			continue;
		}
		clear();
		int j = i;
		while (j <= n && a[ia[j]] == b[ib[L]]) {
			ax[j] = acl.ins(a[ia[j]].L);
			ay[j] = acr.ins(a[ia[j]].R);
			++ j;
		}
		acl.dfs(0);
		acr.dfs(0);
		ss.n = acr.dnt;
		while (i < j) {
			Q.push_back({ ax[i][acl.dfn]				 , ay[i][acr.dfn], ay[i][acr.dfn] + ay[i][acr.siz], 1,  1 });
			Q.push_back({ ax[i][acl.dfn] + ax[i][acl.siz], ay[i][acr.dfn], ay[i][acr.dfn] + ay[i][acr.siz], 1, -1 });
			++ i;
		}
//		acl.build();
//		acr.build();
		while (L < R) {
			int u1 = acl.walk(b[ib[L]].L);
			int u2 = acr.walk(b[ib[L]].R);
			Q.push_back({ u1[acl.dfn], u2[acr.dfn], 0, 0, ib[L] });
			++ L;
		}
		sort(Q.begin(), Q.end(), [](const Qt &a, const Qt &b) {
			return a.x ^ b.x ? a.x < b.x : a.op > b.op;
		});
		for (auto t : Q) {
			if (t.op) {
				ss.add(t.l, t.v);
				ss.add(t.r, -t.v);
			} else {
				ans[t.v] = ss.sum(t.l);
			}
		}
	}
	for (int i = 1; i <= m; ++ i) {
		cout << ans[i] << '\n';
	}
}

#define filename "replace"

int main() {
	#ifdef filename
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Turn = 1;
//	cin >> Turn;
	INIT();
	while (Turn -- ) {
		WORK();
	}
	return 0;
}