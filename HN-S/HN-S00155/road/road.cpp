#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct p{
	int u, v;
	ll w;
} b[4000005];
int n, m, k, F[10005];
ll c[15], a[15][10005];
bool fl = 1;
int findf(int x){
	if(F[x] == x) return x;
	return F[x] = findf(F[x]);
}
bool cmp(p x, p y){
	return x.w < y.w;
}
ll Kruskal(){
	ll mst = 0;
	int cnt = 0;
	sort(b + 1, b + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		int x = b[i].u, y = b[i].v, w = b[i].w;
		int fx = findf(x), fy = findf(y);
		if(fx == fy) continue;
		mst += w;
		F[fx] = fy;
		cnt++;
		if(cnt == n - 1) return mst;
	}
	return mst;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		F[u] = u;
		F[v] = v;
		b[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		if(c[i]) fl = 0;
		bool f = 0;
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(!a[i][j]) f = 1;
		}
		if(!f) fl = 0;
	}
	if(fl){
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				if(!a[i][j]){
					for(int l = 1; l <= n; l++)
						if(l != j)
						b[++m] = {j, l, a[i][l]};
				}
			}
		}
		cout << Kruskal();
		return 0;
	}
	return 0;
}
