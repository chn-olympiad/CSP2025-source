#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
//#define int long long
using namespace std;
typedef long long ll;
const int N = 2e4 + 10, M = 1e6 + 10;

bool Mst;
int n, m, k, c[N], a[15][N], fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
struct qwq {
	int a, b, c;
	bool operator < (const qwq &W) const {
		return c < W.c;
	}
} e[M], e2[M], ek[15][N];
int idx, pos[30], Siz[30];
qwq tmp[30][N];
bool Med;
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0);
//	cerr << abs(&Mst - &Med) / 1048576.0 << "Mb\n";
	clock_t stt = clock();
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) 
		cin >> e[i].a >> e[i].b >> e[i].c;
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) cin >> a[i][j], ek[i][j] = {i + n, j, a[i][j]};
		sort(ek[i] + 1, ek[i] + n + 1);
	}
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= m; i ++) {
		int x = find(e[i].a), y = find(e[i].b);
		if(x == y) continue;
		fa[x] = y;
		e2[++ idx] = e[i];
	}
	swap(e2, e), swap(m, idx); // remain useful edges
	ll res = 1e18;
	for(int s = 0; s < (1 << k); s ++) {
		Siz[0] = 0;
		int tot = 0, lim = 0;
		ll ans = 0;
		for(int i = 1; i <= m; i ++) tmp[0][Siz[0] ++] = e[i];
		for(int i = 1; i <= k; i ++)
			if(s >> i - 1 & 1) {
				ans += c[i];
				tot ++;
				Siz[tot] = 0;
				for(int j = 1; j <= n; j ++) tmp[tot][Siz[tot] ++] = ek[i][j];
			}
		for(int i = 0; i <= tot; i ++) pos[i] = 0;
		for(int i = 1; i <= n + k; i ++) fa[i] = i;
		while(true) {
			qwq o = {0, 0, 2000000000};
			int ii = -1;
			for(int j = 0; j <= tot; j ++) {
				if(pos[j] < Siz[j] && tmp[j][pos[j]] < o) {
					o = tmp[j][pos[j]], ii = j;
				}
			}
			if(ii == -1) break;
			pos[ii] ++;
			int x = find(o.a), y = find(o.b);
			if(x == y) continue;
			fa[x] = y, ans += o.c;
		}
		res = min(res, ans);
	}
	cout << res << '\n';
	cerr << (1.0 * clock() - stt) / CLOCKS_PER_SEC << "s\n";
	
	return 0;
}
