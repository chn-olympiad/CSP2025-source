#include<bits/stdc++.h>
//ccf
//rp++
//481817542 
using namespace std;
int n,m,k,u,v,w,ans;
int fa[10010];
set<array<int,3>> g;
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		g.insert({w,u,v});
	}
	for(auto r : g){
		if(find(r[1]) == find(r[2])) continue;
		ans += r[0];
		fa[find(r[1])] = fa[find(r[2])];
	}
	cout << ans;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
