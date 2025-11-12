#include <bits/stdc++.h>

using namespace std;
int n, m, k, f[20004], siz[20004], cnt[15], c[15];
long long ans;
int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
struct line {
	int u, v, w;
	bool operator <(line x) {
		return w < x.w;
	}
}a[1000006], use[10005], vl[15][10005];
void rf() {
	for(int i = 1; i <= n + k; i ++) {
		f[i] = i;
		siz[i] = 1;
	}
	memset(cnt, 0, sizeof cnt);
}
void hb(int x, int y) {
	x = find(x), y = find(y);
	siz[x] += siz[y];
	f[y] = x;
}
void build() {
	long long ret = 0, cnt = 0;
	for(int i = 1; i <= m; i ++) if(find(a[i].u) != find(a[i].v)) {
		ret += a[i].w;
		hb(a[i].u, a[i].v);
		use[++ cnt] = a[i];
	}
	ans = ret;
//	cout << ans << '\n';
}
void deal(int x) {
	rf();
	vector<int> g;
	long long ret = 0;
	for(int i = 1; i <= k; i ++) if(x & (1 << (i - 1))) g.push_back(i), ret += c[i];
	for(int i = 1; i < n; i ++) {
		for(auto j : g) {
			while(cnt[j] < n && vl[j][cnt[j] + 1].w <= use[i].w) {
				cnt[j] ++;
				int u = vl[j][cnt[j]].u, v = vl[j][cnt[j]].v;
				if(find(u) != find(v)) {
					ret += vl[j][cnt[j]].w;
					hb(u, v);
				}
			}
		}
		if(find(use[i].u) != find(use[i].v)) {
			ret += use[i].w;
			hb(use[i].u, use[i].v);
//			cout << use[i].u << ' ' << use[i].v << '\n';
		}
	}
	ans = min(ans, ret);
//	cout << ret << '\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rf();
	for(int i = 1; i <= m; i ++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) {
			cin >> vl[i][j].w;
			vl[i][j].u = i + n, vl[i][j].v = j;
		}
		sort(vl[i] + 1, vl[i] + 1 + n);
	}
	sort(a + 1, a + 1 + m);
	build();
	for(int i = 1; i < (1 << k); i ++) {
		deal(i);
	}
	cout << ans << '\n';
	return 0;
}


