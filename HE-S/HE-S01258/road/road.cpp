#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;
int n, m, k;
struct Edge {
	int u, v, w;
}e[MAXN];
vector<Edge> v, ov;
int a[15][MAXN], c[15];

int fa[MAXN];
int getf(int pos) {return fa[pos] == pos ? pos : fa[pos] = getf(fa[pos]);}
void merge(int a, int b) {
	// cerr << a << " " << b << endl;
	a = getf(a); b = getf(b);
	if (a == b) return;
	fa[a] = b;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	sort(e + 1, e + m + 1, [](const Edge &a, const Edge &b) {
		return a.w < b.w;
	});

	for (int i = 1; i <= n; i++) fa[i] = i;
	ll sum = 0;
	for (int i = 1; i <= m; i++) {
		// if (e[i].u <= k || e[i].v <= k) continue;
		if (getf(e[i].u) != getf(e[i].v)) {
			merge(e[i].u, e[i].v);
			sum += e[i].w;
			ov.push_back(e[i]);
		}
	}

	// cerr << sum << endl;

	ll ans = sum;
	for (int i = 1; i < (1 << k); i++) {
		int use = i << 1;
		v = ov;
		ll s = 0;
		for (int j = 1; j <= k; j++) if (use >> j & 1) {
			s += c[j];
			for (int x = 1; x <= n; x++) {
				v.push_back({j + n, x, a[j][x]});
			}
		}
		sort(v.begin(), v.end(), [](const Edge &a, const Edge &b) {
			return a.w < b.w;
		});
		// cout << i << ": " << endl;
		// for (auto x : v) {
		// 	cout << x.u << " " << x.v << " " << x.w << endl;
		// }
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		for (int j = 0; j < v.size(); j++) {
			if (getf(v[j].u) != getf(v[j].v)) {
				merge(v[j].u, v[j].v);
				s += v[j].w;
			}
		}
		ans = min(ans, s);
		// cerr << s << endl;
	}

	cout << ans << endl;

	return 0;
}