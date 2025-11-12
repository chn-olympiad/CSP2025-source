#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
#define fst first
#define snd second
using namespace std;
const int MAX=1e4+20, MAXM=1e6+10, INF=1e9;
int t=1, n, m, k, hd[MAX], en, c[11], a[MAX][11], anc[MAX];
pii mn[11];
ll ans;
bool vis[MAXM<<1], visp[MAX], ck;
vector<pii> G[MAX];
struct Edge{
	int v, w, id;
	bool operator< (Edge ojt) const {
		return w<ojt.w;
	}
};
vector<Edge> Gph[MAX];
void dfs(int u, int uu, int num) {
	if (num==n) ck=true;
	if (ck) return;
	Edge mnw={0, INF, 0};
	sort(Gph[u].begin(), Gph[u].end());
	for (auto eg:Gph[u]) {
		if (vis[eg.id]) continue;
		mnw=eg;
		vis[eg.id]=true;
		break;
	}
	if (mnw.v&&!visp[mnw.v]&&!anc[u]) {
//		printf("%d-->%d\n", mnw.v, u);
		G[mnw.v].push_back({u, mnw.w});
		anc[u]=mnw.v;
	}
	for (auto eg:Gph[u]) {
		if (eg.v!=uu&&!visp[eg.v]) {
//			printf("%d:%d\n", u, eg.v);
			visp[eg.v]=true;
			dfs(eg.v, u, num+1);
			visp[eg.v]=false;
		}
	}
}
void dfs2(int u) {
	for (auto eg:G[u]) {
		if (eg.fst>n&&!G[eg.fst].size()) continue;
		if (u>n) ans+=a[eg.fst][u-n];
		else ans+=eg.snd;
		dfs2(eg.fst);
	}
}
void init() {
}
void exe() {
	int u, v, w;
	scanf("%d %d %d", &n, &m, &k);
	if (n==1) {
		putchar('0');
		return;
	}
	for (int i=1;i<=m;i++) {
		scanf("%d %d %d", &u, &v, &w);
		Gph[u].push_back({v, w, i});
		Gph[v].push_back({u, w, i});
	}
	for (int i=1;i<=k;i++) {
		a[0][i]=INF;
		scanf("%d", &c[i]);
		for (int j=1;j<=n;j++) {
			scanf("%d", &a[j][i]);
			Gph[n+i].push_back({j, a[j][i]+c[i], m+(i-1)*n+j});
			if (a[mn[i].fst][i]>=a[j][i]) {
				mn[i].snd=mn[i].fst;
				mn[i].fst=j;
			}
			else if (a[mn[i].snd][i]>=a[j][i]) mn[i].snd=j;
		}
		for (int j=1;j<=n;j++) Gph[j].push_back({n+i, a[j][i]+c[i]+(mn[i].fst==j?a[mn[i].snd][i]:a[mn[i].fst][i]), m+(i-1)*n+j});
	}
	dfs(1, 0, 0);
	for (int i=n+1;i<=n+k;i++) if (!anc[i]) {
		for (auto val:G[i]) anc[val.fst]=0;
		G[i].clear();
	}
//	for (int i=1;i<=n+k;i++) {
//	 	printf("%d:", i);
//	 	for (auto val:G[i]) printf("%d ", val);
//	 	enl;
//	}
	for (int i=1;i<=n;i++) if (!anc[i]) {
		dfs2(i);
		break;
	}
	printf("%lld", ans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//  scanf("%d", &t);
	while (t--) {
		init();
		exe();
	}
	return 0;
}
