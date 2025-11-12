#include <iostream>
#include <algorithm>
#include <map>
#define MAXN (10010)
#define MAXM (1000010)

using namespace std;
typedef long long LL;
int n, m, K;

int head[MAXN << 1], E_cnt;
struct Edge {
	LL w;
	int u, v;
	int next;
} E[MAXM << 1];

void Addedge(int u, int v, LL w) {
	int p = ++ E_cnt;
	E[p].v = v;
	E[p].w = w;
	E[p].u = u;
	E[p].next = head[u];
	head[u] = p;
}

int par[MAXN << 1];
int Find(int x) {
	return par[x] == x ? x : par[x] = Find(par[x]);
}

int head1[MAXN << 1], E1_cnt;
Edge E1[MAXM << 1];

void Addedge1(int u, int v, LL w) {
	int p = ++ E1_cnt;
	E1[p].v = v;
	E1[p].w = w;
	E1[p].u = u;
	E1[p].next = head1[u];
	head1[u] = p;
}

LL ans0 = 0;
map<pair<int, int>, LL> dis;
void Kruskal1() {
	sort(E + 1, E + 1 + E_cnt, [](Edge x, Edge y) {
		return x.w < y.w;
	});
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 1; i <= E_cnt; i++) {
		int v = E[i].v, u = E[i].u, w = E[i].w;
		int pu = Find(u), pv = Find(v);
		if (pu == pv) continue;
		par[pu] = pv;
//		dis[{u, v}] = dis[{v, u}] = w;
		Addedge1(u, v, w);
		ans0 += w;
	}
}

LL ans;
LL C[20];
LL a[20][MAXN];
bool vis[MAXN + 10];

void Kruskal2() {
	sort(E1 + 1, E1 + 1 + E1_cnt, [](Edge x, Edge y) {
		return x.w < y.w;
	});
	for (int i = 1; i <= n + K; i++) par[i] = i;
	for (int i = 1; i <= E1_cnt; i++) {
		int v = E1[i].v, u = E1[i].u, w = E1[i].w;
//		cout << u << " " << v << " " << w << " \n";
	}
	for (int i = 1; i <= E1_cnt; i++) {
		int v = E1[i].v, u = E1[i].u, w = E1[i].w;
		int pu = Find(u), pv = Find(v);
		if (pu == pv) continue;
		if (u > n && !vis[u]) {
			w += C[u - n];
			vis[u] = true;
		}
		par[pu] = pv;
		ans += w;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf ("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; i++) {
		LL u, v, w;
		scanf ("%lld%lld%lld", &u, &v, &w);
		Addedge(u, v, w);
		dis[{u, v}] = dis[{v, u}] = w;
	}
	
	Kruskal1();
	if (K == 0) {
		printf("%lld", ans0);
		return 0;
	}
	
	for (int i = 1; i <= K; i++) {
		cin >> C[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (dis[{i, j}] > a[i][j] + C[i] || dis[{i, j}] == 0) {
				if (i == j) continue; 
				dis[{i, j}] = C[i];
				dis[{j, i}] = C[i];
				Addedge1(n + i, j, a[i][j]);
				cout << i << " " << j << " " << dis[{i, j}]<< "\n";
			}
		}
	}
	
	if (C[1] == 0) {
		printf("0");
		return 0;
	}
	
	Kruskal2();
	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
