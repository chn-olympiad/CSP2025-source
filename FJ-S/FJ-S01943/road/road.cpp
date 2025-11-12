#include <bits/stdc++.h>
#define Max(A, B) (A > B ? A : B)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int read() {
	char e = getchar(); int o = 0;
	while(e < '0' || e > '9') e = getchar();
	while(e >= '0' && e <= '9') o = (o << 1) + (o << 3) + (e ^ 48), e = getchar();
	return o;
}
const int maxn = 1e4 + 5, maxk = 15;
const int maxm = 2e6 + 20 * maxn;
int head[maxn], to[maxm], len[maxm], nxt[maxm], et, n, m, c[maxk], k, a[maxk][maxn];
ll dis[maxn], dist[maxk], ans;
bool vis[maxn], sf[maxn];
void add(int u, int v, int w) {
	to[++et] = v, len[et] = w, nxt[et] = head[u];
	head[u] = et;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1, u, v, w; i <= m; ++i) {
		u = read(), v = read(), w = read();
		add(u, v, w);
		add(v, u, w);
	}
	for(int i = 1; i <= k; ++i) {
		c[i] = read();
		for(int j = 1; j <= n; ++j)
			a[i][j] = read();
	}
	memset(dis, 0x7f, sizeof(dis));
	memset(dist, 0x7f, sizeof dist);
	dis[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push((pii){0ll, 1});
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = nxt[i]){
			if(dis[to[i]] > len[i] && !vis[to[i]]) {
				dis[to[i]] = len[i];
//				cout << dis[to[i]] << ' ' << to [i] << endl;
				pq.push((pii){dis[to[i]], to[i]});
			}
		}
		for(int i = 1; i <= k; ++i) {
			for(int j = 1; j <= n; ++j) {
				int ln = a[k][n] + a[k][u];
				if(!sf[i]) ln += c[i];
				if(dis[j] > ln && !vis[j]) {
					dis[j] = ln;
					pq.push((pii){dis[j], j});
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) {ans += dis[i];//cout << dis[i] << endl;
	}
	printf("%lld", ans);
	return 0;
}
