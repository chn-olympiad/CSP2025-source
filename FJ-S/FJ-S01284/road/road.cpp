/*

首先需要意识到只有 n 条边是有用的。

然后把所有边都加进来，共 nk。对 2 ^ k 种状态跑最小生成树。

O(n * k * 2 ^ k). 大概 1e8 左右，本机应该能跑 0.2s。

update: 他妈的我怎么被卡常了？n=1e3本机跑了1.07s那我不是爆炸了？

不是啊我测了 1s 不是能跑 5e8 吗？ 

操不管了 

*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n, m, k, fa[2002][20002], c[12], a[12][20002];
long long ans[2002], sans = 0x3f3f3f3f3f3f3f3f;
struct node {
	ll x, y, z;
	inline bool operator < (const node bz) const {
		return z < bz.z;
	}
}e[2000002];
ll fd(ll id, ll x) {
	return fa[id][x] == x ? x : fa[id][x] = fd(id, fa[id][x]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (register ll i = 1; i <= n + k; i ++ ) for (register ll j = 0; j < (1 << k); j ++ ) fa[j][i] = i;
	for (register ll i = 1; i <= m; i ++ ) cin >> e[i].x >> e[i].y >> e[i].z;
	for (register ll i = 1; i <= k; i ++ ) { // n + 1 ~ n + k
		cin >> c[i];
		for (ll j = 1; j <= n; j ++ ) cin >> a[i][j];
	}
	sort(e + 1, e + m + 1);
	for (register ll i = 1, x, y, z, fx, fy, cnt = 1; i <= m && cnt < n; i ++ ) {
		x = e[i].x, y = e[i].y, z = e[i].z;
		fx = fd(0, x), fy = fd(0, y);
		if (fx == fy) continue;
		e[cnt ++] = e[i], fa[0][fx] = fy;
	}
	m = n - 1;
	for (register ll i = 1; i <= n + k; i ++ ) fa[0][i] = i;
	for (register ll i = 1; i <= k; i ++ ) for (register ll j = 1; j <= n; j ++ ) e[++ m] = {j, i + n, a[i][j]}; 
	sort(e + 1, e + m + 1);
	for (register ll i = 1, cnt = 0, mc = (n - 1) * (1 << k) + k * (1 << k) / 2, x, y, z, fx, fy, c = 1; i <= m && cnt <= mc; i ++ ) {
		x = e[i].x, y = e[i].y, z = e[i].z;
		for (register ll S = 0; S < (1 << k); S ++ ) {
			fx = fd(S, x), fy = fd(S, y);
			if (fx == fy) continue;
			if (y <= n || (y > n && (S & (1 << (y - n - 1))))) {
				fa[S][fx] = fy, ans[S] += z, cnt ++;
			}
		}
	}
	for (register ll i = 1; i <= k; i ++ ) for (register ll S = 0; S < (1 << k); S ++ ) if ((S >> (i - 1)) & 1) ans[S] += c[i];
	for (register ll S = 0; S < (1 << k); S ++ ) sans = min(sans, ans[S]);
	cout << sans;
}
