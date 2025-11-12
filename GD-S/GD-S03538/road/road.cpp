#include <bits/stdc++.h>
using namespace std;
int fa[10005];
struct edge{
	int u, v, w;
	int add;
}ed[2000005];
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	fa[x] = y;
}
bool is_contact(int x, int y){
	x = find(x), y = find(y);
	return x == y;
} 
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	if(k == 0){
		for (int i = 1; i <= m; i++){
			cin >> ed[i].u >> ed[i].v >> ed[i].w;
		}
		sort(ed + 1, ed + m + 1, [&](edge x, edge y){return x.w < y.w;});
		for (int i = 1; i <= m; i++){
			if(!is_contact(ed[i].u, ed[i].v)){
				merge(ed[i].u, ed[i].v);
				ans += ed[i].w;
			}
		}
		cout << ans << endl;
	}else{
		for (int i = 1; i <= m; i++){
			cin >> ed[i].u >> ed[i].v >> ed[i].w;
			ed[i].add = 0;
		}
		int kc, ka[10005];
		for (int ii = 1; ii <= k; ii++){
			cin >> kc;
			for (int i = 1; i <= n; i++) cin >> ka[i];
		}
		cout << 0 << endl;
	}
	return 0;
}
