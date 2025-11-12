#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define IO
using namespace std;
const int N = 1e4+5, M = 1e6+5, K = 20;
int n, m, k, c[K], a[K][N], fa[N], flag = 1;
struct node{
	int u, v, w;
} e[M];
vector <int> g[N];
bool cmp(node x, node y){
	return x.w < y.w;
}
int find(int x) { return fa[x] = fa[x] == x? x : find(fa[x]); }
void subtask1(){ // no urbanization
	int cnt = 0; 
	long long ans = 0;
	sort(e+1, e+m+1, cmp);
	for (int i = 1, u, v, fu, fv; i <= m; ++i){
		u = e[i].u, v = e[i].v;
		fu = find(u), fv = find(v);
		if (fu != fv){
			fa[fv] = fu;
			ans += e[i].w;
			++cnt;
			if (cnt == n-1) break;
		}
	}
	cout << ans << '\n';
}
void subtask2(){ // with urbanization but no cost
	// 城市化不花钱，与其它点连接也不花钱，所以只要有一个城市化的城市往其余所有点连边即可 0 费构成连通图 
	// 但是为什么说好的 road3 满足特殊性质A ，满足在哪？？？？ 
	cout << 0 << '\n';
}
// 以上 48pts 
void subtask3(){ // k <= 5 16pts
	// 暴力，2^k * n * m
	int cnt = 0;
	long long ans = 0;
	sort(e+1, e+m+1, cmp);
	for (int i = 1, u, v, fu, fv; i <= m; ++i){
		u = e[i].u, v = e[i].v;
		fu = find(u), fv = find(v);
		if (fu != fv){
			fa[fv] = fu;
			ans += e[i].w;
			if (cnt == n-1) break;
		}
	}
	cout << ans << '\n';
}
int main(){
	#ifdef IO
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i){
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[e[i].u].emplace_back(e[i].v);
		g[e[i].v].emplace_back(e[i].u);
	}
	for (int i = 1; i <= k; ++i){
		cin >> c[i];
		if (c[i] != 0) flag = 0;
		for (int j = 1; j <= n; ++j){
			cin >> a[i][j];
			if (a[i][j] != 0) flag = 0;
		}
	}
	if (k == 0) subtask1();
	else if (flag) subtask2();
	else if (k <= 5) subtask3();
	else {
		subtask3();
	}
	
	return 0; 
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
