#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e4 + 5;
int n, m, k, ans = 0;
int a[12][maxn], C[12];
int fa[maxn];
int cnt = 1, L = 1;
struct Node{
	int a, b;
}b[maxn];

int find(int x){
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
bool merge(int l, int r){
	int lf = find(l);
	int rf = find(r);
	if(lf == rf){
		return false;
	}else{
		fa[lf] = rf;
		return true;
	}
}
struct Edge{
	int a, b, w;
	bool operator<(const Edge & temp)const{
		return w < temp.w;
	}
}edges[maxn];
void fan1(){
	
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){//³õÊ¼±ß 
		int u, v, w;
		cin >> u >> v >> w;
		edges[L++] = {u, v, w};
	}
	sort(edges + 1, edges + L);
	for(int i = 1; i < L; i++){
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;
		if(merge(a, b)) ans += w;
	}
	cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if(k == 0){
		fan1();
	}else{
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++){//³õÊ¼±ß 
			int u, v, w;
			cin >> u >> v >> w;
			edges[L++] = {u, v, w};
		}
		for(int i = 1; i <= k; i++){
			cin >> C[i];
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
				if(a[i][j] == 0) b[cnt++] = {i, j};
			}
		}
		for(int i = 1; i < cnt; i++){
			int aa = b[i].a, bb = b[i].b;
			for(int j = 1; j <= n; j++){
				edges[L++] = {bb, j, a[aa][j]};
			}
		}
		sort(edges + 1, edges + L);
		for(int i = 1; i < L; i++){
			int a = edges[i].a;
			int b = edges[i].b;
			int w = edges[i].w;
			if(merge(a, b)) ans += w;
		}
		cout << ans << endl;
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
/*Ren5Jie4Di4Ling5%*/
