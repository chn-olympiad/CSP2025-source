#include <bits/stdc++.h>
#define N 200005
#define M 1000005
#define int long long

using namespace std;

int n, m, k, c[N], fa[N], ans, t;

bool flag = 1;

struct node {
	int fr, to, wi;
	bool operator < (const node & o) const {
		return o.wi < wi;
	}
};

priority_queue<node> q;

int rd() {
	int S = 0, F = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') F = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		S = (S << 3) + (S << 1) + (ch ^ 48);
		ch = getchar();
	}
	return S * F;
}

int find(int k) { return k == fa[k] ? k : fa[k] = find(fa[k]); }

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(); m = rd(); k = rd();
	if(!k) flag = 0;
	for(int x, y, z, i = 0; i < m; i++) {
		x = rd(); y = rd(); z = rd();
		q.push( {x, y, z} );
	}
	for(int i = 1; i <= k; i++) {
		c[i] = rd();
		if(c[i]) flag = 0;
		for(int x, j = 1; j <= n; j++) {
			x = rd();
			if(x) flag = 0;
		}
	}
	if(flag) {
		puts("0");
		return 0;
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 0;
	while(cnt < n - 1) {
		node _ = q.top();
		q.pop();
		int fx = find(_.fr), fy = find(_.to);
		if(fx != fy) {
			fa[fx] = fy;
			ans += _.wi;
			cnt ++;
		}
	}
	printf("%lld", ans);
	return 0;
}
//[0, 20] ·Ö 
