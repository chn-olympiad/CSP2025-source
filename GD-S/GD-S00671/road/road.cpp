#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct edge{
	int to, w;
};
struct road{
	int u, v, w;
}R[1000005];
int fa[10005];
int C[11], A[11][10005];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void uni(int a, int b){
	a = find(a), b = find(b);
	if(a == b)return;
	fa[a] = b;
}
signed main(){
	ios::sync_with_stdio(false);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i{1};i<=n;i++)
		fa[i] = i;
	for(int i{1};i<=m;i++){
		int u, v, w;
		cin >> R[i].u >> R[i].v >> R[i].w;
	}
	for(int i{1};i<=k;i++){
		cin >> C[i];
		for(int j{1};j<=n;j++){
			cin >> A[i][j];
		}
	}
	sort(R + 1, R + 1 + n, [](const road& a, const road& b){
		return a.w < b.w;
	});
	int blocks{n}, cost{};
	for(int i{1};i<=m && blocks > 1;i++){
		int u = find(R[i].u), v = find(R[i].v);
		if(u == v)continue;
		blocks--;
		cost += R[i].w;
		uni(u, v);
	}
	
	
	cout << cost;
	
	return 0;
}
