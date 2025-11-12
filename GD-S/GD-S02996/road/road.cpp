#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
typedef long long LL;

const int N = 1e5 + 10,M = 6e6;
int f[N],c[20],a[20][30000];
int n,m,k;
int cnt;
struct Edge{
	int u,v,w;
}edg[M];

bool cmp(Edge a,Edge b) {
	return a.w < b.w; 
}

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]); 
}

int main () {
	std::freopen("road.in","r",stdin);
	std::freopen("road.out","w",stdout);
	
	std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
	std::cin >> n >> m >> k;
	for (int i = 0; i < N; i ++) f[i] = i;
	for (int i = 1; i <= m; i ++) {
		int a,b,c;
		std::cin >> a >> b >> c;
		edg[++ cnt] = {a,b,c};
	}
	for (int i = 1; i <= k; i ++) {
		std::cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
			edg[++ cnt] = {i,j,a[i][j]};
		}
	}
	std::sort(edg + 1,edg + 1 + cnt,cmp);
	
	LL res = 0;
	for (int i = 1; i <= cnt; i ++) {
		int a = find(edg[i].u),b = find(edg[i].v),w = edg[i].w;
		if (a != b) {
			f[a] = b;
			res += w;
		}
	}
	std::cout << res;
	return 0;
}
