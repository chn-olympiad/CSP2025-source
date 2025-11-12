// B ( road )
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5, M = 2e6 + 5, K = 15;
struct edge{
	int u, v;
	ll w;
};
edge g[M];
int n, m, k;
ll c[K], a[K][N];

ll read();
void write(ll wx);

namespace Keq0{
	int fa[N], cnt;
	ll ans;
	int Find(int fx){
		return (fa[fx] == fx ? fx : fa[fx] = Find(fa[fx]));
	}
	bool cmp(const edge &x, const edge &y){
		return (x.w < y.w);
	}
	void solve(){
		cnt = n;
		for (int i = 1; i <= n; ++i){
			fa[i] = i;
		}
		sort(g + 1, g + m + 1, cmp);
		for (int i = 1, u, v; i <= m && cnt > 1; ++i){
			u = Find(g[i].u);
			v = Find(g[i].v);
			if (u != v){
				ans += g[i].w;
				fa[u] = v;
				--cnt;
			}
		}
		write(ans);
		putchar('\n');
		return;
	}
}

namespace taskA{
	int fa[N], cnt;
	ll ans;
	int Find(int fx){
		return (fa[fx] == fx ? fx : fa[fx] = Find(fa[fx]));
	}
	bool cmp(const edge &x, const edge &y){
		return (x.w < y.w);
	}
	void solve(){
		for (int i = 1, zr; i <= k; ++i){
			zr = 0;
			for (int j = 1; j <= n; ++j){
				if (a[i][j] == 0){
					zr = j;
				}
			}
			for (int j = 1; j <= n; ++j){
				if (j != zr){
					++m;
					g[m].u = zr;
					g[m].v = j;
					g[m].w = a[i][j];
				}
			}
		}
		cnt = n;
		for (int i = 1; i <= n; ++i){
			fa[i] = i;
		}
		sort(g + 1, g + m + 1, cmp);
		for (int i = 1, u, v; i <= m && cnt > 1; ++i){
			u = Find(g[i].u);
			v = Find(g[i].v);
			if (u != v){
				ans += g[i].w;
				fa[u] = v;
				--cnt;
			}
		}
		write(ans);
		putchar('\n');
		return;
	}
}

namespace taskAll{
	int tot, fa[N + K], cnt;
	edge g2[M];
	ll sum, ans;
	int Find(int fx){
		return (fa[fx] == fx ? fx : fa[fx] = Find(fa[fx]));
	}
	bool cmp(const edge &x, const edge &y){
		return (x.w < y.w);
	}
	void calc(){
		cnt = tot;
		for (int i = 1; i <= tot; ++i){
			fa[i] = i;
		}
		for (int i = 1; i <= m; ++i){
			g2[i] = g[i];
		}
		sort(g2 + 1, g2 + m + 1, cmp);
		ll now = sum;
		for (int i = 1, u, v; i <= m && cnt > 1; ++i){
			u = Find(g2[i].u);
			v = Find(g2[i].v);
			if (u != v){
				now += g2[i].w;
				fa[u] = v;
				--cnt;
			}
		}
		ans = (ans < now ? ans : now);
		return;
	}
	void dfs(int cur){
		if (cur > k){
			calc();
			return;
		}
		dfs(cur + 1);
		++tot;
		sum += c[cur];
		for (int i = 1; i <= n; ++i){
			++m;
			g[m].u = tot;
			g[m].v = i;
			g[m].w = a[cur][i];
		}
		dfs(cur + 1);
		--tot;
		sum -= c[cur];
		m -= n;
		return;
	}
	void solve(){
		ans = 1e18;
		tot = n;
		dfs(1);
		write(ans);
		putchar('\n');
		return;
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool subtaskA = true;
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= m; ++i){
		g[i].u = read();
		g[i].v = read();
		g[i].w = read();
	}
	for (int i = 1; i <= k; ++i){
		c[i] = read();
		bool fag = false;
		for (int j = 1; j <= n; ++j){
			a[i][j] = read();
			if (a[i][j] == 0){
				fag = true;
			}
		}
		if (c[i] != 0 || !fag){
			subtaskA = false;
		}
	}
	if (k == 0){
		Keq0::solve();
		return 0;
	}
	if (subtaskA){
		taskA::solve();
		return 0;
	}
	taskAll::solve();
	return 0;
}
ll read(){
	ll rx = 0;
	char rch = getchar();
	while (rch < '0' || '9' < rch){
		rch = getchar();
	}
	while ('0' <= rch && rch <= '9'){
		rx = (rx << 3) + (rx << 1) + (rch ^ 48);
		rch = getchar();
	}
	return rx;
}
void write(ll wx){
	static char ws[25];
	int wtp = 0;
	do{
		ws[++wtp] = wx % 10;
		wx /= 10;
	}while(wx);
	while (wtp){
		putchar(ws[wtp--] | 48);
	}
	return;
}
