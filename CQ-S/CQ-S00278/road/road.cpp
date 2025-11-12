#include <bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
const LL N = 1e6 + 5;
LL n, m, k, ans = 1e18;
LL c[N], fa[N], esz[N];
struct Edge {
	LL x, y, w;
	bool operator < (const Edge A) const { return w < A.w; }
} e[15][N], ee[N];
LL find_fa(LL x) { return fa[x] ? fa[x] = find_fa(fa[x]) : x; }
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(LL i = 1, x, y, w; i <= m; i ++ ) {
		cin >> x >> y >> w;
		e[0][i] = {x, y, w};
	}
	sort(e[0] + 1, e[0] + m + 1);
	for(LL i = 1; i <= k; i ++ ) {
		cin >> c[i];
		esz[i] = n;
		for(LL j = 1, w; j <= n; j ++ ) {
			cin >> w;
			e[i][j] = {i + n, j, w};
		}
		sort(e[i] + 1, e[i] + n + 1);
	}
	for(LL i = 1; i <= m; i ++ ) {
		LL x = find_fa(e[0][i].x), y = find_fa(e[0][i].y);
		if(x != y) {
			ee[ ++ esz[0]] = e[0][i];
			fa[x] = y;
		}
	}
	for(LL i = 1; i <= esz[0]; i ++ ) e[0][i] = ee[i];
	for(LL i = 0; i < 1ll << k; i ++ ) {
		LL sum = 0, cnt = 0;
		for(LL j = 1; j <= k; j ++ )
			if(i >> j - 1 & 1) {
				sum += c[j];
				cnt ++ ;
			}
		LL pos[15], cntend = 0;
		for(LL j = 0; j <= k; j ++ ) pos[j] = 1;
		for(LL j = 1; j <= n + k; j ++ ) fa[j] = 0;
		while(cntend < cnt + 1) {
			LL mini = -1;
			for(LL j = 0; j <= k; j ++ )
				if((!j || i >> j - 1 & 1) && pos[j] <= esz[j] && (mini == -1 || e[j][pos[j]].w < e[mini][pos[mini]].w))
					mini = j;
			Edge t = e[mini][pos[mini]];
			LL x = find_fa(t.x), y = find_fa(t.y);
			if(x != y) {
				sum += t.w;
				fa[x] = y;
			}
			pos[mini] ++ ;
			if(pos[mini] > esz[mini]) cntend ++ ;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}
//long long

