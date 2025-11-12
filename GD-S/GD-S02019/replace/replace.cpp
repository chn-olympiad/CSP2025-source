#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mkp make_pair
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define debug(x) cout << #x << " " << x << "\n";

bool MemoryST;

const int bas = 131;
const int N = 1e6 + 10;
const int M = 1e6 + 10;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353; 

struct hsh {
	int h1, h2;
	hsh(int h11 = 0, int h22 = 0) {
		h1 = h11; h2 = h22;
	}
};
	hsh operator + (hsh x, hsh y) {
		return hsh((x.h1 + y.h1) % mod1, (x.h2 + y.h2) % mod2); 
	}
	hsh operator * (hsh x, hsh y) {
		return hsh(1ll * x.h1 * y.h1 % mod1, 1ll * x.h2 * y.h2 % mod2);
	}
	bool operator < (hsh x, hsh y) {
		if (x.h1 != y.h1) return x.h1 < y.h1;
		return x.h2 < y.h2;
	}
	bool operator == (hsh x, hsh y) {
		return (x.h1 == y.h1 && x.h2 == y.h2); 
	}

struct BIT {
	int n, t[N];
	void init(int nn) {
		n = nn;
		for (int i = 1; i <= n; ++i)
			t[i] = 0;
	}
	int lowbit (int x) {
		return x & (-x);
	}
	void add (int x, int v) {
		for (; x <= n;x += lowbit(x))
			t[x] += v;
	}
	int que (int r) {
		int s = 0;
		for (; r; r -= lowbit(r))
			s += t[r];
		return s;
	}
} bt;

pair<hsh,hsh> dfi[N];

int n, q;
string s[N][2];
int id[N], ty[N], rid[N];
int ps[N], psl[N], psr[N], ans[N];
int tim, df[M], lw[M], cnt, tr[M][27];

pair<hsh,hsh> solve(string &s1, string &s2) {
	if (s1.size() != s2.size() || s1 == s2) return mkp(hsh(-1, -1), hsh(-1, -1)); 
	int l1 = 0, l2 = 0;
	int len = s1.size();
	while (s1[l1] == s2[l2])
		l1++, l2++;
	int r1 = len - 1, r2 = len - 1;
	while (s1[r1] == s2[r2])
		r1--, r2--;
	hsh p1 = hsh(0, 0),p2 = hsh(0, 0);
	rep(i, l1, r1)
		p1 = p1 * hsh(bas, bas) + hsh(s1[i], s1[i]);
	rep(i, l2, r2)
		p2 = p2 * hsh(bas, bas) + hsh(s2[i], s2[i]);
	string t1 = "", t2 = "";
	per(i, l1 - 1, 0)
		t1 += s1[i];
	rep(i, r1 + 1, len - 1)
		t2 += s1[i];
	s1 = t1; s2 = t2;
	return mkp(p1, p2);
}

int ins(string s) {
	int u = 1;
	for (int i = 0; i < (int)s.size(); ++i) {
		int x = s[i] - 'a';
		if (!tr[u][x]) tr[u][x] = ++cnt;
		u = tr[u][x];
	}
	return u; 
}

void dfs(int u) {
	if (!u) return ;
	df[u] = ++tim;
	for (int i = 0; i < 26; ++i)
		dfs(tr[u][i]);
	lw[u] = tim;
}

vector<pii> qu[N];
vi up[N];

void getans(int l, int r) {
	rep(i, 1, cnt)
		rep(j, 0, 25)
			df[i] = tr[i][j] = 0;
	cnt = 1; tim = 0;
	rep(i, l, r)
		ps[i] = ins(s[id[i]][0]);
	dfs(1);
	int c1 = cnt;
	rep(i, 0, c1 + 1)
		qu[i].clear(), up[i].clear();
	rep(i, l, r)
		psl[i] = df[ps[i]], psr[i] = lw[ps[i]];
	rep(i, l, r) {
		if (ty[id[i]])
			up[psl[i]].pb(id[i]);
		else
			qu[psl[i]].pb(mkp(id[i], 1)),
			qu[psr[i] + 1].pb(mkp(id[i], -1));
	}
	rep(i, 1, cnt)
		rep(j, 0, 25)
			df[i] = tr[i][j] = 0; 
	cnt = 1; tim = 0;
	rep(i, l, r)
		ps[i] = ins(s[id[i]][1]);
	dfs(1);
	rep(i, l, r)
		psl[i] = df[ps[i]], psr[i] = lw[ps[i]];
	bt.init(cnt);
	rep(i, 1, c1) {
		for (auto v : qu[i]) {
			int u = rid[v.fi];
			bt.add(psl[u], v.se);
			bt.add(psr[u] + 1, -v.se);
//			cout << psl[u] << " " << psr[u] << " " << v.se << "\n";
		}
		for (auto v : up[i]) {
			int u = rid[v];
			ans[v] += bt.que(psl[u]);
//			cout << "que :: " << psl[u] << "\n"; 
		}
	}
}

void Mainsolve() {
	cin >> n >> q;
	rep(i, 1, n)
		cin >> s[i][0] >> s[i][1];
	q += n;
	rep(i, n + 1, q)
		cin >> s[i][0] >> s[i][1];
	int len = 0;
	rep(i, 1, q)
		len += s[i][0].size(), len += s[i][1].size();
	rep(i, 1, q) {
		id[i] = i;
		if (i <= n) ty[i] = 0;
		else ty[i] = 1;
		dfi[i] = solve(s[i][0], s[i][1]);
	}
	sort(id + 1, id + q + 1, [&](int x, int y) {
		return dfi[x] < dfi[y];
	});
	rep(i, 1, q)
		rid[id[i]] = i;
	rep(i, 1, q) {
		int j = i;
		while(j < q && dfi[id[j + 1]] == dfi[id[i]])
			++j;
		if (dfi[id[i]].fi.h1 != -1)
			getans(i, j);
		i = j;
	}
	for (int i = n + 1; i <= q; ++i)
		cout << ans[i] << "\n";
}

bool MemoryED;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr << fixed << setprecision(6) << (&MemoryST-&MemoryED) / 1024.0/ 1024.0 << "MB\n";

	int T = 1; //cin >> T;
	while (T--) Mainsolve();

	cerr << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";

//	system("fc .out .out") ;
	return 0;
}

