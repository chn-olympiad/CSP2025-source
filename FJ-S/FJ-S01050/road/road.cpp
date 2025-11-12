#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void read(T& x) {
	x = 0;
	char c;
	while(!isdigit(c = getchar()));
	do
		x = x * 10 + (c ^ 48);
	while(isdigit(c = getchar()));
}

int N, M, K, g[11], fa[10014], sz[10014];
int tfa[10014], tsz[10014];

int find(int x) {
	if(x == fa[x])
		return x;
	return find(fa[x]);
}

bool merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y)
		return false;
	if(sz[x] < sz[y])
		swap(x, y);
	fa[y] = x;
	sz[x] = max(sz[x], sz[y] + 1);
	return true;
}

struct Edge {
	int u, v;
	ll w;
} es[1010006];
bool operator<(Edge a, Edge b) {
	return a.w < b.w;
}
int cnt;
ll ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(N), read(M), read(K);
	for(int i = 0; i < M; i ++) {
		read(es[cnt].u), read(es[cnt].v), read(es[cnt].w);
		cnt ++;
	}
	for(int i = 1; i <= K; i ++) {
		read(g[i]);
		for(int j = 1; j <= N; j ++) {
			es[cnt] = {N + i, j, 0};
			read(es[cnt].w);
			cnt ++;
		}
	}
	for(int i = 1; i <= N + K; i ++)
		fa[i] = i, sz[i] = 1;

	sort(es, es + cnt);
	for(int i = 0; i < cnt; i ++)
		if(merge(es[i].u, es[i].v))
			ans += es[i].w;

	printf("%lld\n", ans);
	return 0;
}
