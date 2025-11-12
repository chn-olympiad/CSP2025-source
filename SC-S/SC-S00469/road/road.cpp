#include <bits/stdc++.h>
using namespace std;
template<typename T> void read(T &x) { x = 0; char c = getchar(); while(!isdigit(c)) c = getchar(); while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar(); }
template<typename T, typename... Args> void read(T &x, Args &...args) { read(x), read(args...); }
typedef long long ll;
const int N = 1e4 + 15, M = 1e6 + 10, K = 15;
int n, m, k, c[K], p[N], v[K][N];
struct Edge{
	int a, b, w;
	bool operator< (const Edge &W)const{
		return w < W.w;
	}
}edges[M], tmp[M];
int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k);
	for(int i = 0; i < m; i ++) {
		read(edges[i].a, edges[i].b, edges[i].w);
		edges[i].a --, edges[i].b --;
	}
	sort(edges, edges + m);
	for(int i = 0; i < n; i ++) p[i] = i;
	int tot = 0;
	for(int i = 0; i < m; i ++) {
		int a = find(edges[i].a), b = find(edges[i].b);
		if(a != b) {
			p[a] = b;
			edges[tot ++] = edges[i];
		}
	}
	for(int i = 0; i < k; i ++) {
		read(c[i]);
		for(int j = 0; j < n; j ++) read(v[i][j]);
	}
	ll res = 1e18;
	for(int i = 0; i < (1 << k); i ++) {
		ll sum = 0;
		int num = n + __builtin_popcount(i);
		for(int j = 0; j < n + k; j ++) p[j] = j;
		for(int j = 0; j < n; j ++)	tmp[j] = edges[j];
		tot = n;
		for(int j = 0; j < k; j ++)
			if(i >> j & 1) {
				sum += c[j];
				for(int k = 0; k < n; k ++) tmp[tot ++] = {j + n, k, v[j][k]};
			}
		sort(tmp, tmp + tot);
		int cnt = 0;
		for(int j = 0; j < tot; j ++) {
			int a = find(tmp[j].a), b = find(tmp[j].b);
			if(a != b) {
				cnt ++;
				sum += tmp[j].w;
				if(cnt == num - 1) break;
				p[a] = b;
			}
		}
		res = min(res, sum);
	}
	printf("%lld\n", res);
	return 0;
}