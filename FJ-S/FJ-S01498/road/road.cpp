#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e4+5;
int n, m, fa[N], cntedges, k;
struct edge {
	int u, v;LL w;
	
	friend bool operator < (edge x, edge y) {
		return x.w > y.w;
	}
}edges[N];
priority_queue<edge> q;
LL ans, c[15], a[15][N], mind[15];
bitset<N> used[15];

int Find(int u){return u==fa[u]?u:fa[u]=Find(fa[u]);}
void Merge(int u, int v){fa[Find(u)] = Find(v);}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m >> k;
	while(m--) {
		int u, v;LL w;
		cin >> u >> v >> w;
		q.push({u, v, w});
	}
	if(k==0) {
		for(int i = 1; i <= n; i++)fa[i] = i;
		int cnt = n;
		while(!q.empty()) {
			edge e = q.top();q.pop();
			if(Find(e.u) != Find(e.v)) {
				cnt--;
				Merge(e.u, e.v);
				ans += e.w;
				edges[++cntedges] = e;
			}
		}
		printf("%lld\n", ans);
	}
	else {
		for(int j = 1; j <= k; j++) {
			cin >> c[j];
			mind[j] = 0;
			a[j][0] = 1e18;
			for(int i = 1; i <= n; i++) {
				cin >> a[j][i];
				if(a[j][i] < a[j][mind[j]])mind[j] = i;
			}
		}
		for(int i = 1; i <= n; i++)fa[i] = i;
		int cnt = n;
		while(!q.empty()) {
			edge e = q.top();q.pop();
			if(Find(e.u) != Find(e.v)) {
				cnt--;
				Merge(e.u, e.v);
				ans += e.w;
				edges[++cntedges] = e;
			}
		}
		//printf("%lld\n", sum);
		//return 0;
		for(int S = 1; S < (1<<k); S++) {
			LL s2 = 0;
			//printf("S:%d\n", S);
			for(int i = 1; i <= k; i++) {
				used[i].reset();
				if((S>>(i-1))&1)s2 += c[i], used[i][mind[i]] = true;
			}
			for(int i = 1; i <= cntedges; i++) {
				LL w = edges[i].w;
				int u = edges[i].u, v = edges[i].v, usecountry = 0;
				for(int j = 1; j <= k; j++) if((S>>(j-1))&1) {
					LL w2 = 0;
					if(v != mind[j] && !used[j][v])w2 += a[j][v];
					else if(u != mind[j] && !used[j][u])w2 += a[j][u];
					if(w2 < w)w = w2, usecountry = j;
				}
				if(edges[i].w == w)s2 += w;
				if(usecountry)used[usecountry][u] = used[usecountry][v] = true;
			}
			for(int i = 1; i <= k; i++)for(int j = 1; j <= n; j++)if(used[i][j])s2 += a[i][j];
			ans = min(ans, s2);
			//printf("%lld\n", s2);
		}
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
