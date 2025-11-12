// GZ-S00427 °²Ë³¶þÖÐ ÕÔÑØ¿­ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (a); i <= (b); ++ i)
#define fir first
#define sec second

const int N = 1e4 + 10, M = 1e6 + 10, K = 11;
int n, m, k, fa[N * K], cnt = 0, counter[K], connect[K], cnt_fir[K], p[N];
pair<int, pair<int, int>> edges[M + K * 1010 * 1010 / 2];

int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void join(int u, int v) { fa[find(u)] = find(v); }

bool chk(int u, int v) {
	if(u > (k + 1) * n && v <= (k + 1) * n) {
		FOR(j, 0, k) if(find(u) == find(v % n + j * n)) return true;
		return false;
	}
	if(v > (k + 1) * n && u <= (k + 1) * n) {
		FOR(j, 0, k) if(find(v) == find(u % n + j * n)) return true;
		return false;
	}
	if(u > (k + 1) * n && v > (k + 1) * n) return find(u) == find(v);
	if(u <= (k + 1) * n && v <= (k + 1) * n) {
		FOR(i, 0, k) FOR(j, 0, k) if(find(u % n + i * n) == find(v % n + j * n)) return true;
		return false;
	}
	return false;
}

int kruskal() {
	sort(edges + 1, edges + cnt + 1);
	int res = 0;
	FOR(i, 1, cnt) {
		int w = edges[i].fir, u = edges[i].sec.fir, v = edges[i].sec.sec;
		if(u > v) swap(u, v); // u real, v not
		if(v > (k + 1) * n) {
			if(1 <= u && u <= n) {
				if(cnt_fir[v - (k + 1) * n] == 1) continue;
				cnt_fir[v - (k + 1) * n] = 1;
			}
		}
		if(!chk(u, v)) {
			join(u, v);
			counter[u] ++, counter[v] ++;
			connect[u] = w, connect[v] = w;
			res += w;
			printf("connect %lld & %lld: %lld, res = %lld\n", u, v, w, res);
		}
	}
	return res;
}

void subA() {
	FOR(i, 0, N - 1) fa[i] = i;
	FOR(i, 1, m) {
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		edges[++ cnt] = make_pair(w, make_pair(u, v));
	}
	FOR(i, 1, k) {
		int c;
		scanf("%lld", &c);
		FOR(j, 1, n) scanf("%lld", &p[j]);
		FOR(x, 1, n) FOR(y, x + 1, n) edges[++ cnt] = make_pair(p[x] + p[y], make_pair(x, y));
	}
	sort(edges + 1, edges + cnt + 1);
	int ans = 0;
	FOR(_, 1, cnt) {
		int w = edges[_].fir, u = edges[_].sec.fir, v = edges[_].sec.sec;
		if(find(u) != find(v)) {
			fa[find(u)] = find(v);
			ans += w;
		}
	}
	printf("%lld\n", ans);
	return;
}

void sub0() {
	FOR(i, 0, N - 1) fa[i] = i;
	FOR(i, 1, m) {
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		edges[++ cnt] = make_pair(w, make_pair(u, v));
	}
	sort(edges + 1, edges + cnt + 1);
	int ans = 0;
	FOR(_, 1, cnt) {
		int w = edges[_].fir, u = edges[_].sec.fir, v = edges[_].sec.sec;
		if(find(u) != find(v)) {
			fa[find(u)] = find(v);
			ans += w;
		}
	}
	printf("%lld\n", ans);
	return;	
}

signed main() {
	freopen("road.in", "r", stdin);freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	if(k != 0) subA(); // road3
	else sub0();
	return 0;
}
/*

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
