#include<bits/stdc++.h>
#define RD read()
#define rep(i, x, y) for(int i = x;i <= y;++ i)
using namespace std;
int read(){
	int x = 0, f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0';ch = getchar();}
	return x * f;
}
const int M = 2e6 + 10, N = 1e4 + 50;
int n, m, k;
long long ans = 2e17;
int c[N], a[20][N], cnt;
bool vis[20];
struct node{
	int u, v, c;
}edge[M];
int f[N];
int find(int x){if(f[x] != x) f[x] = find(f[x]);return f[x];}
bool cmp(node a, node b){return a.c < b.c;}
void check(long long sum, int q){
	rep(i, 1, n + k) f[i] = i;
	int res = 0;
	rep(i, 1, cnt){
		if(sum > ans) return;
		int u = edge[i].u, v = edge[i].v;
		if(find(u) == find(v)) continue;
		if(u > n && !vis[u - n]) continue;
		f[find(u)] = f[find(v)];
		sum += edge[i].c;
		++ res;
		if(res == q - 1) break;
	}
	ans = min(ans, sum);
}
void dfs(int p, long long sum, int q){
	if(sum > ans) return;
	if(p > k){
		check(sum, q);
		return;
	}
	dfs(p + 1, sum, q);
	vis[p] = 1;
	dfs(p + 1, sum + c[p], q + 1);
	vis[p] = 0;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = RD;m = cnt = RD;k = RD;
	rep(i, 1, m){
		edge[i].u = RD;
		edge[i].v = RD;
		edge[i].c = RD;
	}
	rep(i, 1, k){
		c[i] = RD;
		rep(j, 1, n){
			edge[++ cnt].u = n + i;
			edge[cnt].v = j;
			edge[cnt].c = RD;
		}
	}
	sort(edge + 1, edge + cnt + 1, cmp);
	dfs(1, 0, n);
	printf("%lld", ans);
	return 0;
}
