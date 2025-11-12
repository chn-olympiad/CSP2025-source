#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXM = 1e6 + 10;
const int MAXN = 1e4 + 10;

struct Edge_t
{
	int from, to, weight;
	bool operator < (const Edge_t& q) {return weight < q.weight;}	
}edges[MAXM];

int n, m, k;
int fa[MAXN];
int find(int x) {return (fa[x] == x) ? x : fa[x] = find(fa[x]);}

long long ans;
void solve() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	
	sort(edges + 1, edges + 1 + n);
//	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		if (find(edges[i].from) != find(edges[i].to)) {
			fa[find(edges[i].from)] = fa[find(edges[i].to)];
			ans += edges[i].weight;
		}
	}
}
int c[MAXN];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 1; i <= m; i++) {                               
		int from, to, wei;
		scanf("%d %d %d", &from, &to, &wei);
		edges[i] = {from, to, wei};
	}
	solve();
	printf("%d", ans);
	return 0;
}
