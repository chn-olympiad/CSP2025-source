#include <bits/stdc++.h>
#define all(x) x.begin (), x.end ()
#define x first
#define y second
using namespace std;
using ll = long long;
using db = double;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

template <typename T>
void cmax (T &a, const T &b) {if (a < b) a = b;}
template <typename T>
void cmin (T &a, const T &b) {if (a > b) a = b;}

template <typename T>
ostream & operator << (ostream &os, vector <T> &a) {
	for (auto &v : a) os << v << ' ';
	return os;
}

void init () {
	
}

void solve () {
	int n; cin >> n;
	vector <array <ll, 3>> a (n, array <ll, 3> ({0ll, 0ll, 0ll}));
	for (auto &vec : a) for (int i = 0; i < 3; i++)
		cin >> vec[i];
	
	auto get = [&](pair <ll, int> &s, int x) -> pair <ll, int> {
		pair <ll, int> maxn = {0ll, 0};
		for (int i = 0; i < 3; i++) if (i != s.y)
			cmax (maxn, make_pair (a[x][i], i));
		return maxn;
	};
	
	using T = priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>>;
	array <T, 3> q;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		pair <ll, int> s = {0ll, 0};
		for (int j = 0; j < 3; j++) cmax (s, make_pair (a[i][j], j));
		pair <ll, int> t = get (s, i);
		q[s.y].emplace (s.x - t.x, i); ans += s.x;
		if (q[s.y].size () > n / 2) {
			auto v = q[s.y].top (); q[s.y].pop ();
			ans -= v.x;
			
			pair <ll, int> maxn = {0ll, 0};
			for (int j = 0; j < 3; j++) if (j != s.y)
				cmax (maxn, make_pair (a[v.y][j], j));
			q[maxn.y].emplace (maxn.x, i);
		}
	}
	
	cout << ans << '\n';
}

int main () {
#ifndef LOCAL
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
#endif
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	
	init ();
	
	int t = 1;
	cin >> t;
	while (t--) solve ();
}
