#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= inf(b); i--)
#define gc getchar
template<typename T> void read(T &x) {x=0; char c, s = 1;while (!isdigit(c=gc())) if (c=='-') s = -1;for (; isdigit(c); c=gc()) x = (x<<1)+(x<<3)+(c^48);x*=s;}
template<typename TT, typename ...T> void read(TT &x, T &...y) {read(x), read(y...);}
const int N = 1e5 + 10;
const int M = 4e6 + 10;
int n, m, k, c, a[N], vis[N], b[20], head[N], cnt;
struct E {
	int v, w, id, nex;
}e[M];
void add(int x, int y, int z, int id) {
	e[++cnt].nex = head[x];
	e[cnt].v = y, e[cnt].w = z, e[cnt].id = id;
	head[x] = cnt;
}
ll prim() {
	ll ans = 0;
	priority_queue<Pii> Q;
	rep(i, 1, n+k) vis[i] = 0;
	int tot = 1;
	vis[1] = 1;
	for (int i = head[1]; i; i = e[i].nex)
		if (b[e[i].id] && !vis[e[i].v]) Q.push({-e[i].w, i});
	while (tot < n+c) {
		int ind = Q.top().second; Q.pop();
		if (vis[e[ind].v]) continue;
		//printf("Got %d by %d\n", e[ind].v, e[ind].w);
		vis[e[ind].v] = 1, ans += e[ind].w, tot++;
		for (int i = head[e[ind].v]; i; i = e[i].nex) {
			if (b[e[i].id] && !vis[e[i].v]) Q.push({-e[i].w, i});
		}
	}
	return ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k);
	rep(i, 1, m) {
		int x, y, z; read(x, y, z);
		add(x, y, z, 0), add(y, x, z, 0);
	}
	rep(i, 1, k) {
		read(a[i]);
		rep(j, 1, n) {
			int x; read(x);
			add(n+i, j, x, i), add(j, n+i, x, i);
		}
	}
	ll ans = INFL; b[0] = 1;
	rep(i, 0, (1<<k)-1) {
		ll sum = 0; c = 0;
		rep(j, 1, k) if (i & (1<<(j-1))) b[j] = 1, sum += a[j], c++; else b[j] = 0;
		ll p = prim();
		//printf("cost %lld %lld\n", p, sum);
		ans = min(ans, p+sum);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
