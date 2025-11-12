#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define rer(i, l, r, a) rep1(i, l, r) read(a[i])
#define fst first
#define snd second
#define mp make_pair
#define eb emplace_back
#define il inline
#define ptc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 5e6 + 2e5 + 10, inf = ~0U >> 2, INF = ~0U >> 1;
namespace stupid_lrc {
	template <typename T> il void read(T &x) {
		x = 0; char ch; int f = 1;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T, typename ...L> il void read(T &x, L &...y) {
		read(x); read(y...);
	}

	template <typename T> il void read(pair <T, T> &x) {
		read(x.fst, x.snd);
	}

	il int read() {
		int x; read(x); return x;
	}

	template <typename T> il void gmin(T &x, T y) {
		x = x < y ? x : y;
	}

	template <typename T> il void gmax(T &x, T y) {
		x = x > y ? x : y;
	}
}
using namespace stupid_lrc;
int n, q, rt[MAXN]; string x, y, z;
const int mod = 1011451423, base = 131;
const int P = 1e7 + 19;

struct my_hash {
	size_t operator ()(const pll &x) const {
		return (x.fst * mod + x.snd) % P;
	}
};
unordered_map <pll, int, my_hash> id;

il pll fun(string x, string y) {
	int i = 0, j = x.size() - 1;
	while (x[i] == y[i]) ++i;
	while (x[j] == y[j]) --j;
	ll h1 = 0, h2 = 0;
	rep1(k, i, j) {
		h1 = (h1 * base + x[k]) % mod;
		h2 = (h2 * base + y[k]) % mod;
	} return {h1, h2};
}

struct trie {
	int tot, son[MAXN][30], sum[MAXN], fail[MAXN], pa[MAXN];
	
	il void insert(int u) {
		int p = u; pa[p] = p;
		for (auto ch : z) {
			int c = ch - 'a', &t = son[u][c];
			if (!t) t = ++tot;
			u = t; pa[u] = p;
		} ++sum[u];
	}
	
	il void init() {
		queue <int> q;
		rep1(i, 0, id.size() - 1) {
			int u = rt[i];
			rep1(j, 0, 25) if (son[u][j]) q.emplace(son[u][j]);
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			sum[x] += sum[fail[x]];
			rep1(i, 0, 25) {
				int &t = son[x][i];
//				cout << x << ' ' << i << ' ' << t << ' ' << fail[x] << ' ' << son[fail[x]][i] << endl;
				if (t) fail[t] = son[fail[x] ? fail[x] : pa[x]][i], q.emplace(t);
				else t = son[fail[x] ? fail[x] : pa[x]][i];
			}
		}
	}
	
	il int query(int u) {
		int res = 0;
		for (auto ch : z) {
			int c = ch - 'a';
			u = son[u][c] ? son[u][c] : pa[u];
			res += sum[u];
		} return res;
	}
} T;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n, q);
	rep1(i, 1, n) {
		cin >> x >> y; z.clear();
		if (x == y) continue;
		rep1(i, 0, x.size() - 1) z += x[i], z += y[i];
		pll now = fun(x, y);
		if (!id.count(now)) id[now] = id.size(), rt[id[now]] = ++T.tot;
		T.insert(rt[id[now]]);
	} T.init();
//	return 0;
//	rep1(i, 1, T.tot) cout << i << ' ' << T.fail[i] << endl;
	rep1(_, 1, q) {
		cin >> x >> y; z.clear();
//		assert(x != y);
		rep1(i, 0, x.size() - 1) z += x[i], z += y[i];
		pll now = fun(x, y);
		if (id.count(now)) {
			printf("%d\n", T.query(rt[id[now]]));
		} else puts("0");
//		if (_ == 774) cout << x << ' ' << y << ' ' << rt[id[now]] << endl, exit(0);
	}
//	cerr << "!" << T.tot << endl;
	return 0;
}

