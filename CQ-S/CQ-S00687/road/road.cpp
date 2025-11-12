#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

int read() {
	int w = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		w = w * 10 + ch - '0';
		ch = getchar();
	}
	return w * f;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + '0');
	else {
		write(x / 10);
		putchar(x % 10 + '0');
	}
}

const int N = 10010, M = 1e6 + 10, K = 20;

struct E {
	int u, v, w;
	bool operator < (E x) {
		return w < x.w;
	}
} edge[M << 2], b[M << 2];

int n, m, k;
int fa[N << 1];
int a[K][N];

int find(int x) {
	return fa[x] = fa[x] == x ? x : find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) {
		edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j <= n; j++) {
			a[i][j] = read();
		}
	}
	
	sort(edge + 1, edge + 1 + m);
	
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	ll res = 0;
	int idx = 0, pc = 0;
	for(int i = 1; i <= m; i++) {
		int x = find(edge[i].u), y = find(edge[i].v);
		b[++idx] = edge[i];
		if(x != y) {
			fa[x] = y;
			res += edge[i].w;
			pc++;
			if(pc == n - 1 && n >= 1000 && m > 100000) break;
		}
	}
	
	int tmp = idx;
	for(int i = tmp + 1; i <= min(tmp * 3, m); i++) b[++idx] = edge[i];

	tmp = idx;
	for(int i = 0; i < (1 << k); i++) {
		idx = tmp;
		ll p = 0;
		for(int j = 1; j <= k; j++) {
			if((i >> j - 1) & 1) {
				p += a[j][0];
				for(int l = 1; l <= n; l++) {
					idx++;
					b[idx].u = l, b[idx].v = j + n, b[idx].w = a[j][l];
				}
			}
		}
		sort(b + 1, b + 1 + idx);
		
		for(int j = 1; j <= n + n; j++) fa[j] = j;
		
		for(int j = 1; j <= idx; j++) {
			int x = find(b[j].u), y = find(b[j].v);
			if(x != y) {
				p += b[j].w;
				fa[x] = y;
			}
		}
		
		res = min(res, p);
	}
	
	write(res);
	
	return 0;
}
/*
莫名其妙的 UB
调了一万年不知道哪错了 
S炸了 
*/ 
