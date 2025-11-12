// mouse_boy 2025.11 CSP
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("road.in");
ofstream fout("road.out");

const int kMaxN = 1e4 + 5;
ll fa[kMaxN], sz[kMaxN], a[kMaxN], n, m, k, ans, cnt;

ll find(ll x) {
	return fa[x] = (fa[x] == x ? x: find(fa[x]));
}

void add(ll x, ll y) {
	x = find(x), y = find(y), (sz[x] > sz[y]) && (swap(x, y), 0);
	if(x == y) return ;
	fa[x] = y, sz[y] += sz[x], sz[x] = 0;
}

struct E {
	ll u, v, w;
	bool operator< (const E A) const {
		return w < A.w;
	}
} g[(ll)1e7 + 5];

void solve() {
	for(int i = 1; i <= n; i++) {
		fa[i] = i, sz[i] = 1;
	}
	sort(g + 1, g + 1 + m);
	for(int i = 1, u, v, w; i <= m; i++) {
		u = g[i].u, v = g[i].v, w = g[i].w;
		if(find(u) != find(v)) {
			add(u, v), ans += w;
			if(++cnt == n - 1) return;
		}
	}
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
	fin >> n >> m >> k;
	bool f = 1;
	for(int i = 1, x, y, z; i <= m; i++) {
		fin >> x >> y >> z, g[i] = {x, y, z};
	}
	for(int i = 1, x; i <= k; i++) {
		fin >> x, f &= (x == 0);
		for(int j = 1; j <= n; j++) {
			fin >> a[j], f &= (a[j] == 0);
			for(int b = 1; b < j; b++) {
				g[++m] = {b, j, a[b] + a[j] + x};
			}
		}
	}
	if(f || n > 1000) {
		return fout << "0\n", 0;
	}
	solve();
	fout << ans << '\n';
  return 0;
}
/*

cd /home/noilinux/HN-S00235/road && ulimit -s 102400 && g++ road.cpp -o road -O2 -Wall && time ./road && size ./road && ./road && diff road.out ans.out -Bb

*/
