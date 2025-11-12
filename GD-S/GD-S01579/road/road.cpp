#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using pll = pair<ll, ll>;
template<typename T1, typename T2> bool chkmin(T1 &a, const T2 &b) { return b < a ? (a = b, true) : false; }
template<typename T1, typename T2> bool chkmax(T1 &a, const T2 &b) { return b > a ? (a = b, true) : false; }
void fileIO(const string& x) { freopen((x + ".in").c_str(), "r", stdin); freopen((x + ".out").c_str(), "w", stdout); } 
mt19937_64 gen(random_device{}());
ll test_case = 1, test_num = 1;
const int int_Inf = 1e9; const ll Inf = 1e18;

const ll N = 1e4 + 5, K = 10 + 5;

ll n, m, k, c[K];
vector<pll> a[K]; 

struct DSU {
	ll fa[N];
	void init(ll n) { for(int i = 1; i <= n; i++) fa[i] = i; }
	ll find(ll x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	bool merge(ll x, ll y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		fa[y] = x;
		return true;
	}
} d;

struct Edge {
	ll u, v, w;
	Edge() {}
	Edge(ll u_, ll v_, ll w_) : u(u_), v(v_), w(w_) {}
	bool operator < (const Edge &rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> edg;

void solution() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		edg.emplace_back(u, v, w);
	}
	sort(edg.begin(), edg.end(), [](const Edge e1, const Edge e2) { return e1.w < e2.w; });
	
	vector<Edge> tmp_edg;
	d.init(n);
	for(auto [u, v, w] : edg) {
		if(d.find(u) == d.find(v)) continue;
		d.merge(u, v);
		tmp_edg.emplace_back(u, v, w);
	}
	edg = tmp_edg;
	
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			ll x; cin >> x;
			a[i].emplace_back(x, j);
		}
		sort(a[i].begin(), a[i].end());
	}
	
	ll ans = Inf;
	for(int S = 0; S < (1 << k); S++) {
		ll res = 0;
		vector<Edge> vec;
		for(int i = 0; i < k; i++) if((S >> i) & 1) {
			res += c[i];
			vector<Edge> tmp(n);
			for(int j = 0; j < n; j++) tmp[j] = { a[i][0].second, a[i][j].second, a[i][j].first };
			vec.insert(vec.end(), tmp.begin(), tmp.end());
			inplace_merge(vec.begin(), vec.end() - n, vec.end());
			
			res += a[i][0].first;
		}
		vec.insert(vec.end(), edg.begin(), edg.end());
		inplace_merge(vec.begin(), vec.end() - (n - 1), vec.end());
		
//		for(auto [u, v, w] : vec) cout << "(" << u << " " << v << " " << w << ")";
//		cout << "\n";
		
//		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
		
//		for(auto [val, x] : vec) cout << "[" << val << " " << x << "]";
//		cout << "\n";
		
//		int i = 0;
//		while(i < edg.size() && )
		
		d.init(n);
		for(auto [u, v, w] : vec) {
			if(d.find(u) == d.find(v)) continue;
			res += w;
			d.merge(u, v);
		}
		
		chkmin(ans, res);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fileIO("road");
	
	solution();
	
	return 0;
}

