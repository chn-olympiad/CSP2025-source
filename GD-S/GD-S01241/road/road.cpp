#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int fa[maxn] , n;
void init(){
	for(int i = 1 ; i <= n ; i++){
		fa[i] = i;
	}
}
int find(int u){
	if(fa[u] != u){
		return fa[u] = find(fa[u]);
	}
	return fa[u];
}
void inv(int u , int v){
	if(find(u) != find(v)){
		fa[u] = fa[v];
	}
}
struct edge{
	int u , v , w;
};
bool cmp(edge z , edge y){
	return z.w < y.w;
}
edge s[maxn];
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int u1 , v1 , w1;
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	init();
	int ans = 0;
	sort(s + 1 , s + 1 + m , cmp);
	for(int i = 1 ; i <= m ; i++){
		if(find(s[i].u) != find(s[i].v)){
			ans += s[i].w;
			inv(s[i].u , s[i].v);
		}
	}
	cout << ans;
	return 0;
}
