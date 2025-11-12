#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 1000005;
int n, m, k;
struct edge{
	int u, v, w;
}a[MAXM];
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int fa[MAXN];
int findfa(int x){
	if(fa[x] == x){
		return x;
	}
	fa[x] = findfa(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		if(a[i].u < a[i].v){
			swap(a[i].u, a[i].v);
		}
	}
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			int fffff;
			cin >> fffff;
		}
	}
	sort(a + 1, a + 1 + m, cmp);
	long long ans = 0;
	for(int i = 1; i <= m; i++){
		if(findfa(a[i].u) != findfa(a[i].v)){
			fa[fa[a[i].v]] = a[i].u;
			ans += a[i].w;
		}
	}
	cout << ans;
	return 0;
}
/*
7 10 0
1 2 1
1 4 5
1 7 4
2 3 9
2 5 1
4 5 9
4 6 1
5 6 4
5 7 8
6 7 1

*/
