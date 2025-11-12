#include <bits/stdc++.h>

#define _for(i, a, b) for (int i = (a); i <= (int)(b); i ++ )

using namespace std;

typedef array<int, 3> arr;
typedef long long LL;
const int N = 1e6 + 10;
int n, m, k, cnt;
int c[N];
struct Edge{
	int u, v, w;
}a1[N], a2[N], a[12][100010];
int p[N];

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

inline int find(int x) {
	return (x == p[x] ? x : (p[x] = find(p[x])));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	_for (i, 1, n) p[i] = i;
	_for (i, 1, m)
		cin >> a1[i].u >> a1[i].v >> a1[i].w;
	sort(a1 + 1, a1 + m + 1, cmp);
	LL zlj = 0;
	_for (i, 1, m) {
		int aa = a1[i].u, bb = a1[i].v, w = a1[i].w;
		int x = find(aa), y = find(bb);
		if (x != y) {
			p[x] = y;
			a[0][ ++ cnt] = a1[i];
			zlj += w;
		}
	}
	cnt = 0;
	
	_for (i, 1, k) {
		cin >> c[i];
		_for (j, 1, n) {
			cin >> a[i][j].w;
			a[i][j].v = j;
			a[i][j].u = n + i;
		}
		sort(a[i] + 1, a[i] + n + 1, cmp);
	}
	LL res = 1e18;
	
	_for (pp, 0, (1 << k) - 1) {
		LL ans = 0, cnt = 0, now = n - 1;
		int pos[12];
		_for (i, 0, n + 10) {
			p[i] = i;
			if (i <= 10) pos[i] = 1;
		}
		_for (i, 1, k) if (pp >> (i - 1) & 1) ans += c[i], now ++;
		while (cnt < now) {
			int id = -1, w = 0;
			_for (i, 0, k) 
				if (!i || (pp >> (i - 1) & 1)) {
					while (pos[i] <= (n - (!i))) {
						int u = a[i][pos[i]].u, v = a[i][pos[i]].v, w1 = a[i][pos[i]].w;
						if (find(u) != find(v)) {
							if (w1 < w || id == -1) {
								id = i, w = w1;
							}
							break;
						}
						pos[i] ++;
					}
				}
			if (id == -1) break;
			cnt ++;
			int u = a[id][pos[id]].u, v = a[id][pos[id]].v;
			p[find(u)] = find(v), ans += w;
			pos[id] ++;
		}
		// cout << ans << ' ' << pp << '\n';
		
		if (cnt == now) res = min(res, ans);
		// cout << ans << ' ' << pos[0] << ' ' << pos[1] << ' ' << pos[2] << '\n';
	}
	
	cout << res << '\n';
	return 0;
}
