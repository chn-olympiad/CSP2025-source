#include<iostream>
#include<algorithm>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long

#define gch ch = getchar()
void read(int & x) { x = 0; char gch; while(!isdigit(ch)) gch; while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), gch; }

const int N = 1e4 + 84, M = 1e6 + 16;
int n, m, k, _;

ll ans;
int tot[20];
struct EDge {
	int u, v, w;
} ed[M], eg[20][N];

int fa[N], siz[N];
void init_fa() { for(int i = 1; i <= n + k; ++i) fa[i] = i, siz[i] = 1; }
int get(const int x) { if(x == fa[x]) return x;; return fa[x] = get(fa[x]); }
void us(int u, int v) {
	u = get(u), v = get(v);
	if(siz[u] < siz[v]) siz[v] += siz[u], fa[u] = v;
	else siz[u] += siz[v], fa[v] = u;
}

void get_ed() {
	init_fa();
	sort(ed + 1, ed + 1 + m, [](const EDge A, const EDge B) { return A.w < B.w; });
	for(int i = 1; i <= m; ++i) {
		int u = ed[i].u, v = ed[i].v, w = ed[i].w;
		if(get(u) == get(v)) continue;
		us(u, v);
		ans += w;
		eg[0][++tot[0]] = ed[i];
	}
}
bool xf = true;
int c[N], a[N], id[N];
void get_eg(const int i) {
	read(c[i]);
	xf &= (c[i] == 0);
	bool pt = false;
	for(int j = 1; j <= n; ++j) {
		read(a[j]);
		pt |= (a[j] == 0);
		id[j] = j;
	}
	xf &= pt;
	sort(id + 1, id + 1 + n, [](const int A, const int B) { return a[A] < a[B]; });
	for(int j = 1; j <= n; ++j) eg[i][++tot[i]] = { i + n, id[j], a[id[j]] };
}

const int inf = 0x3f3f3f3f;
int pos[20];
void getans(const int S) {
	ll sum = 0;
	for(int i = 1; i <= k; ++i) pos[i] = n + n + n;
	for(int i = 1; i <= k; ++i) if(S & (1 << (i - 1))) sum += c[i], pos[i] = 1;
	if(sum >= ans) return ;
	init_fa();
	pos[0] = 1;
	for(int tim = 1; tim < n + k; ++tim) {
		int val = inf, u = 0, v = 0;
		for(int i = 0; i <= k; ++i) if(!i or (S & (1 << (i - 1)))) {
			while(pos[i] <= tot[i] and get( eg[i][pos[i]].u ) == get( eg[i][pos[i]].v )) pos[i]++;
			if(pos[i] > tot[i]) continue;
			if(val > eg[i][pos[i]].w) {
				val = eg[i][pos[i]].w;
				u = eg[i][pos[i]].u, v = eg[i][pos[i]].v;
			}
		}
		if(!u) break;
		sum += val; us(u, v);
		if(sum >= ans) return ;
	}
	ans = sum;
}
int mian() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n); read(m); read(k);
	for(int i = 1; i <= m; ++i) read(ed[i].u), read(ed[i].v), read(ed[i].w);
	get_ed();
	for(int i = 1; i <= k; ++i) get_eg(i);
	if(xf) getans( (1 << k) - 1 );
	else { for(int S = 1; S < (1 << k); ++S) getans(S); }
	printf("%lld\n", ans);
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/