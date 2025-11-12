#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
#define ll long long
int inline read() {
	int num = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { num = (num << 3) + (num << 1) + (ch ^ 48); ch = getchar(); }
	return num * f;
}
int n, m, k; 
int cnt; 
ll res, ans; 
int c[N], a[15][N]; 
struct edge { int u, v, w; } e[M];
bool cmp(edge A, edge B) { return A.w < B.w; }
int fa[N]; 
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int& check(int &p1, int &p2) {
	if(p1 > m) return p2; 
	else if(p2 > cnt) return p1; 
	else if(e[p1].w < e[p2].w) return p1; 
	else return p2; 
}
void init() {
	for(int i = 1; i <= n; ++i) fa[i] = i; 
	for(int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w; 
		u = find(u), v = find(v); 
		if(u != v) fa[v] = u, e[++cnt] = e[i]; 
	}
	m = n - 1; 
}
ll solve(int sta) {
	res = 0, cnt = m; 
	int t = n; 
	for(int i = 1; i <= n + k; ++i) fa[i] = i; 
	for(int i = 1; i <= k; ++i) if((sta >> (i - 1)) & 1) {
		res += c[i], ++t; 
		for(int j = 1; j <= n; ++j) {
			++cnt; 
			e[cnt].u = n + i; 
			e[cnt].v = j; 
			e[cnt].w = a[i][j]; 
		}
	}
	if(cnt > m) sort(e + m + 1, e + cnt, cmp); 
	int p1 = 1, p2 = m + 1; 
	while(t > 1) {
		int &id = check(p1, p2); 
		int u = e[id].u, v = e[id].v, w = e[id].w; 
		u = find(u), v = find(v); 
		if(u != v) {
			--t; 
			res += w; 
			fa[v] = u; 
		} ++id; 
	}
	return res; 
}
int main() {
#define file
#ifdef file
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	n = read(), m = read(), k = read(); 
	for(int i = 1; i <= m; ++i) e[i].u = read(), e[i].v = read(), e[i].w = read(); 
	sort(e + 1, e + 1 + m, cmp); 
	init(); 
	for(int i = 1; i <= k; ++i) {
		c[i] = read(); 
		for(int j = 1; j <= n; ++j) a[i][j] = read(); 
	}
	ans = 9e18; 
	for(int sta = 0; sta < (1 << k); ++sta) ans = min(ans, solve(sta)); 
	printf("%lld", ans); 
	return 0;
}
/*
没有城市化便是最小生成树
否则不就是相当于加上这几个点的最小生成树吗
add: 
似乎加了点之后的最小生成树应该在原来的最小生成树的基础上进行修改。 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
