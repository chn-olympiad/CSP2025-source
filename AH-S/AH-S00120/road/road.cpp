#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool st;
int read() {
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
int lowbit(int x) {
	return x & (-x);
}
const int N = 1e4 + 20, M = 1e6, K = 10;
int n, m, qk, c[K + 10], a[K + 3][N + 3];
ll sum[(1 << K) + 10];
namespace dsu {
	int fa[N + 10], siz[N + 10];
	int Find(int x) {
		if(fa[x] == x) return x;
		else return fa[x] = Find(fa[x]);
	} 
	void Union(int u, int v) {
		int U = Find(u), V = Find(v);
		if(siz[U] > siz[V]) swap(U, V);
		siz[V] += siz[U];
		fa[U] = V;
	}
	void reset(int limit) {
		for(int i = 1; i <= limit; i++)
			fa[i] = i, siz[i] =1;
	}
}
struct edge {
	int fr, to, val;
	bool operator < (const edge &other) const {
		return val < other.val;
	}
} y[M + 10];
vector <edge> ya, yb, yc[K + 10];
vector <edge> yp[(1 << K) + 10];

ll kruskal(int S) {
	dsu::reset(n + qk);
	int j = 0;
	vector <edge> ed;
	for(int i = 0; i < ya.size(); i++) {
		while(j < yb.size())
			if(yb[j] < ya[i]) 
				ed.push_back(yb[j]), j++;
			else break;
		ed.push_back(ya[i]);
	}
	while(j < yb.size()) ed.push_back(yb[j]), j++;

	ll ans = 0; yp[S].clear();
	for(int i = 0; i < ed.size(); i++) {
		int u = ed[i].fr, v = ed[i].to, w = ed[i].val;
		if(dsu::Find(u) != dsu::Find(v)) {
			ans += w;
			dsu::Union(u, v);
			yp[S].push_back(ed[i]);
		}
	}
	return ans;
}
bool ed;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), qk = read();
	for(int i = 1; i <= m; i++)
		y[i].fr = read(), y[i].to = read(), y[i].val = read();
	for(int i = 0; i < qk; i++) {
		c[i] = read();
		for(int j = 1; j <= n; j++)
			a[i][j] = read();
	}

	sort(y + 1, y + m + 1);
	dsu::reset(n);
	ll ans = 0;
	for(int i = 1; i <= m; i++) {
		int u = y[i].fr, v = y[i].to, w = y[i].val; 
		if(dsu::Find(u) != dsu::Find(v)) {
			ans += w;
			dsu::Union(u, v);
			ya.push_back(y[i]);
		}
	}

	for(int S = 1; S < (1 << qk); S++) {
		int j = 0, t = __lg(lowbit(S)), pre = S - lowbit(S);
		yb.clear();
		if((1 << t) == S) {
			sum[S] = c[t];
			for(int j = 1; j <= n; j++)
				yb.push_back((edge){n + 1 + t, j, a[t][j]});
			sort(yb.begin(), yb.end());
			yc[t] = yb;
		}
		else {
			sum[S] = sum[pre] + c[t];
			int k = 0;
			for(int j = 0; j < yc[t].size(); j++) {
				while(k < yp[pre].size())
					if(yp[pre][k] < yc[t][j]) yb.push_back(yp[pre][k]), k++;
					else break;
				yb.push_back(yc[t][j]);
			}
			while(k < yp[pre].size()) yb.push_back(yp[pre][k]), k++;
		}
		ll tmp = kruskal(S) + sum[S];
		// cout << (1 << qk) << ' ' << S << ' ' << sum[S] << ' ' << tmp - sum[S] << endl;
		// cout << S << ' ' << tmp << endl;
		ans = min(ans, kruskal(S) + sum[S]);
	} 
	cout << ans << '\n';
	// cerr << (&st - &ed) / 1024.0 / 1024.0 << endl;
}