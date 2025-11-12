#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll getInt() {
	ll s = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	
	while (isdigit(c)) {
		s = s * 10 + c - '0';
		c = getchar(); 
	}
	
	return s * f;
}

const int M = 1e6 + 10;
const int N = 1e4 + 10;

ll n, m, k; 

struct Edge {
	ll u, v, w;
};

Edge edge[2 * M];

ll fa[N], size[N];

ll find(ll x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
} 

bool merge(ll x, ll y) {
	x = find(x), y = find(y);
	bool flag = x != y; 
	if (flag) {
		if (size[x] > size[y]) swap(x, y);
		fa[x] = y;
		size[y] += size[x];
	}
	return flag;
}

void solve1() {
	sort(edge + 1, edge + m + 1, [](Edge x, Edge y) {
		return x.w < y.w;
	});
	
	ll cost = 0;
	
	for (int i = 1; i <= m; ++i) {
		if (merge(edge[i].u, edge[i].v)) {
			cost += edge[i].w;
		}
	}
	
	printf("%lld\n", cost); 
	
} 

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = getInt();
	m = getInt();
	k = getInt();
		
	for (int i = 1; i <= n + k; ++i) {
		fa[i] = i;
		size[i] = 1;
	}
	
	for (int i = 1; i <= m; ++i) {
		ll u = getInt(), v = getInt(), w = getInt();
		edge[i] = {u, v, w};
	}
	
	for (int i = 1; i <= k; ++i) {
		ll c = getInt();
		for (int j = 1; j <= n; ++j) {
			ll w = getInt();
			edge[++m] = {n + i, j, w};
		}
	}
	
	n += k;
	
//	if (k == 0) {
//		solve1();
//	}
	
	solve1();
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
4 6 0
1 2 1
2 3 1
3 2 5
1 4 5
2 4 1
2 1 6
*/
