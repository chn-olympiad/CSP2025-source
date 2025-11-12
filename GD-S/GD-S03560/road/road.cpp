#include<bits/stdc++.h>
#define ll long long
#define pair pair<int, int>

using namespace std;

const ll N = 2e4 + 10, M = 2e6 + 10, inf = 1e18;

inline ll read(){
	char c = getchar(); ll x = 0, s = 1;
	while(!isdigit(c)) {
		if(c == '-') s = -1;
		c = getchar();
	}
	while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return s * x; 
}

struct edge{
	ll u, v, w;
}G[M];

ll c[20], d[20][N];

ll fa[N];

ll find(ll u) {
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

ll now, n, m, k;

bool operator < (edge &x, edge &y) {
	return x.w < y.w;
}

ll solve(ll sum) {
	sort(G + 1, G + now + 1);
	ll res = 0, cnt = 0;
	for(int i = 1; i <= now; ++i) {
		ll u = G[i].u, v = G[i].v, w = G[i].w;
		if(find(u) != find(v)) {
 			fa[u] = v;
			res += w;
			if(++cnt == sum - 1 + n) break;
		}
		
	}
	return res;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(ll i = 1; i <= m; ++i) {
		G[i] = {read(), read(), read()};
	}
	for(ll i = 1; i <= k; ++i) {
		c[i] = read();
		for(ll j = 1; j <= n; ++j) {
			d[i][j] = read();
		}
	}
	ll ans = inf;
	for(ll i = 0; i < (1 << k); ++i) {
		ll cnt = 0, sum = 0;
		now = m;
		for(ll j = 0; j < k; ++j) {
			if((1 << j) & i) {
				for(ll l = 1; l <= n; ++l) {
					G[++now] = {n + j + 1, l, d[j + 1][l]};
				}
				sum += c[j + 1];
				++cnt;
			}
		}
		for(ll j = 1; j <= n + k; ++j) fa[j] = j;
		ans = min(ans, solve(cnt) + sum); 
	}
	cout << ans << "\n" ;
	return 0;
}



