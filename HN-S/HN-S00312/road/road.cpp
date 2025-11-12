#include <bits/stdc++.h>

#define fir first
#define sec second

#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)

#define mkp make_pair
#define epb emplace_back
#define pb pop_back
#define sz(a) (int)(a.size())
#define All(a) begin(a), end(a)
#define mem(a, x) memset(a, x, sizeof(a))

using namespace std;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename T>
void chkmax(T &x, T y) {
	if (x < y) x = y;
}
template<typename T>
void chkmin(T &x, T y) {
	if (x > y) x = y;
}

const int kN = 1e4 + 10 + 5;

const int kK = 15;

int n, m, k;

vector<tuple<int, int, int> > org_e;

vector<tuple<int, int, int> > new_e;

int val[kK];

namespace dsu {

int fa[kN];
int siz[kN];
int nxt[kN], ed[kN];

void init() {
	L(i, 1, n + k) {
		fa[i] = i;
		nxt[i] = 0;
		ed[i] = i;
		siz[i] = 1;
	}
}

int find(int x) {
	return fa[x];
}

bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	if (siz[x] < siz[y]) swap(x, y);
	siz[x] += siz[y];
	int cur = y;
	while (cur) {
		fa[cur] = x;
		cur = nxt[cur];
	}
	nxt[ed[x]] = y;
	ed[x] = ed[y];
	return true;
}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	L(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		org_e.epb(w, u, v);
	}
	sort(All(org_e));
	dsu::init();
	for (auto it : org_e) {
		int u = get<1>(it), v = get<2>(it);
		if (dsu::merge(u, v)) {
			new_e.epb(it);
		}
	}
	L(i, 1, k) {
		cin >> val[i];
		L(j, 1, n) {
			int w; cin >> w;
			new_e.epb(w, j, i + n);
		}
	}
	sort(All(new_e));
	ll ans = (ll)1e18;
	L(s, 0, (1 << k) - 1) {
		ll sum = 0;
		L(i, 1, k) {
			if (s & (1 << i - 1)) sum += val[i];
		}
		dsu::init();
		for (auto it : new_e) {
			int u = get<1>(it), v = get<2>(it);
			if (v > n && !(s & (1 << v - n - 1))) continue;
			if (dsu::merge(u, v)) {
				sum += get<0>(it);
			}
		}
		// cerr << s << ' ' << sum << '\n';
		chkmin(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
