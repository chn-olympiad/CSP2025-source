#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;
// #define int ll
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

struct ly {
	int u, v;
	ll w;
};

struct lyy {
private:
	int n;
	vector<int> fa, v;

public:
	lyy(const int _n) {
		n = _n;
		fa.resize(_n + 1);
		iota(fa.begin() + 1, fa.end(), 1);
		v.resize(_n + 1, 1);
		v[0] = 0;
	}
	void reset() {
		fill(v.begin() + 1, v.end(), 1);
		iota(fa.begin() + 1, fa.end(), 1);
	}
	int f(const int x) {
		return x == fa[x] ? x : fa[x] = f(fa[x]);
	}
	bool same(const int x, const int y) {
		return f(x) == f(y);
	}
	void merge(int x, int y) {
		x = f(x);
		y = f(y);
		if (x == y) {
			return;
		}
		if (v[x] < v[y]) {
			swap(x, y);
		}
		v[x] += v[y];
		v[y] = 0;
		fa[y] = x;
	}
};

void Main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> c(k + 1);
	vector<ly> edge;
	auto add = [&](const pair<int, int> p, const ll w) {
		edge.push_back({p.first, p.second, w});
	};
	for (int i = 1; i <= m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		add(minmax(u, v), w);
	}
	bool chk = false;
	for (int i = 1; i <= k; ++i) {
		bool tmp = true;
		cin >> c[i];
		if (c[i] != 0) {
			tmp = false;
		}
		for (int j = 1; j <= n; ++j) {
			ll x;
			cin >> x;
			if (x != 0) {
				tmp = false;
			}
			add(minmax(i + n, j), x);
		}
		if (tmp) {
			chk = true;
		}
	}
	if (chk) {
		cout << 0 << endl;
		return;
	}
	stable_sort(edge.begin(), edge.end(), [&](const ly &l, const ly &r) {
		return l.w < r.w;
	});
	lyy dsu(n + k);
	ll res = LLONG_MAX;
	for (int bit = 0; bit < 1 << k; ++bit) {
		ll curres = 0;
		int curk = 0;
		for (int i = 1; i <= k; ++i) {
			if (bit & (1 << (i - 1))) {
				curres += c[i];
				++curk;
			}
		}
		dsu.reset();
		int cnt = 0;
		for (const ly cur: edge) {
			if (cnt >= n + k - 1) {
				break;
			}
			const int u = cur.u, v = cur.v;
			const ll w = cur.w;
			if ((u > n && !(bit & (1 << (u - n - 1)))) || (v > n && !(bit & (1 << (v - n - 1))))) {
				continue;
			}
			if (dsu.same(u, v)) {
				continue;
			}
			dsu.merge(u, v);
			curres += w;
			++cnt;
		}
		res = min(res, curres);
	}
	cout << res << endl;
}

// #define CSPS_MULTI_TEST_CASES

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
#ifdef CSPS_MULTI_TEST_CASES
	cin >> t;
#endif
	while (t--) {
		Main();
	}
	return cout << flush, fflush(stdout), 0;
}

