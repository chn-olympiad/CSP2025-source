#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 100, maxm = 1e6 + 1;
struct Node{int from, to; ll val;}edge[maxm<<1], kdge[11][maxn<<1], EDGE[maxn << 2];
bool operator<(Node a, Node b){return a.val < b.val;}
int dsu[maxn], c[11];
int findfa(int u){return (dsu[u] == u ? u : dsu[u] = findfa(dsu[u]));}
int n, m, k;
ll mst(int x){
	int cnt = (m<<1);
	ll ret = 0;
	for(int i = 1; i <= (m<<1); i++) EDGE[i] = edge[i];
	for(int t = 1; x; x >>= 1, t++){
		if(x & 1){
			ret += c[t];
			for(int i = 1; i <= (n<<1); i++)
				EDGE[++cnt] = kdge[t][i];
		}
	}
	sort(EDGE + 1, EDGE + cnt + 1);
	for(int i = 1; i <= cnt; i++){
		if(findfa(EDGE[i].from) == findfa(EDGE[i].to)) continue;
		dsu[findfa(EDGE[i].from)] = findfa(EDGE[i].to);
		ret += EDGE[i].val;
	}return ret;
}
int main(){
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, u, v, w; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);
		edge[(i<<1) - 1] = {u, v, w};
		edge[i<<1] = {v, u, w};
	}
	for(int i = 1, a; i <= k; i++){
		scanf("%d", &c[i]);
		for(int j = 1, u; j <= n; j++){
			scanf("%d", &u);
			kdge[i][(j<<1) - 1] = {n + i, j, u};
			kdge[i][j<<1] = {j, n + i, u};
		}
	}ll res = (1ll<<60);
	for(int i = 0; i < (1<<k); i++){
		for(int j = 1; j <= n + k; j++) dsu[j] = j;
		res = min(res, mst(i));
	}printf("%lld", res);
	return 0;
}
