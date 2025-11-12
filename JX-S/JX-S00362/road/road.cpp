#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e4 + 7, M = 2e6 + 7, K = 11;
typedef long long ll;
typedef pair <int, int> pll;
int n, m, k;
struct node{int u, v, w;};
node e[M], stk[N];
int c[N], fa[N], tot, cost[K][N], top;
int d[K], t;
ll mn = 0x3f3f3f3f3f3f3f3f;
bool cmp(node x, node y){
	return x.w < y.w;
}
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void add(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return ;
	fa[x] = y;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 0; i < k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> cost[i][j];
	}
	for(int i = 1; i <= m; i++){
		if(find(e[i].u) == find(e[i].v)) continue;
		add(e[i].u, e[i].v), stk[++tot] = e[i];
	}
	for(int i = 0; i < (1 << k); i++){
		top = t = 0;
		ll res = 0;
		for(int j = 0; j < k; j++)
			if(i & (1 << j)) d[++t] = j, res = res + c[j];
		for(int j = 1; j <= tot; j++) e[++top] = stk[j];
		for(int j = 1; j <= t; j++)
			for(int q = 1; q <= n; q++)
				e[++top] = (node){n + j, q, cost[d[j]][q]};
		sort(e + 1, e + top + 1, cmp);
		int cnt = 0;
		for(int j = 1; j <= n + t; j++) fa[j] = j;
		for(int j = 1; j <= top; j++){
			if(find(e[j].u) == find(e[j].v)) continue;
			res += e[j].w, add(e[j].u, e[j].v), cnt++;
		}
		if(cnt == n + t - 1) mn = min(mn, res);
	}
	cout << mn << "\n";
	return 0;
}
