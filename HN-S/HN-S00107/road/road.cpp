#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;


#ifdef _Joler_
#define debug(x) cout<<(#x)<<" = "<<(x)<<'\n'
#else
#define debug(x) ;
#define cin fin
#define cout fout
ifstream fin("road.in");
ofstream fout("road.out");
#endif

int fa[10500];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool un(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	fa[a] = b;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector <array<int, 3> > ve(m);
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		ve[i] = {c, a, b};
	}
	sort(ve.begin(), ve.end());
	vector <int> vk(k);
	vector <vector<array<int, 3> > > vp(k, vector<array<int, 3> > (n));
	for (int i = 0; i < k; i++) {
		cin >> vk[i];
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vp[i][j] = {a, n + i, j};
		}
		sort(vp[i].begin(), vp[i].end());
	}
	const int K = 1<<k;
	auto f = [&](int n, const vector<array<int, 3> >& va, const vector<array<int, 3> >& vb) {
		for (int i = 0; i <= n + k; i++) {
			fa[i] = i;
		}
		int a = 0, b = 0, cnt = 0;
		ll res = 0;
		while (a < va.size() && b < vb.size()) {
			if (cnt == n) return res;
			if (va[a][0] <= vb[b][0]) {
				if (un(va[a][1], va[a][2])) {
					res += va[a][0];
					cnt++;
				}
				a++;
			} else {
				if (un(vb[b][1], vb[b][2])) {
					res += vb[b][0];
					cnt++;
				}
				b++;
			}
		}
		while (a < va.size()) {
			if (cnt == n) return res;
			if (un(va[a][1], va[a][2])) {
				res += va[a][0];
				cnt++;
			}
			a++;
		}
		while (b < vb.size()) {
			if (cnt == n) return res;
			if (un(vb[b][1], vb[b][2])) {
				res += vb[b][0];
				cnt++;
			}
			b++;	
		}
		return res;
	};
	ll ans = INF;
	for (int i = 0; i < K; i++) {
		vector <array<int, 3> > vb;
		int cnt = __builtin_popcount(i);
		ll base = 0;
		vb.reserve(cnt * n);
		for (int j = 0; j < k; j++) {
			if (i >> j & 1) {
				base += vk[j];
				for (const auto& a : vp[j]) {
					vb.emplace_back(a);
				}
			}
		}
		sort(vb.begin(), vb.end());
		ans = min(ans, f(n + cnt, ve, vb) + base);
	}
	cout << ans << '\n';
	
	
	return 0;
}
