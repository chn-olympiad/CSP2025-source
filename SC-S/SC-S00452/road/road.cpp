#include<bits/stdc++.h>
using namespace std;
const int Max_n = 1e4 + 10;
int n, m, k;
struct S{
	int v, w;
};
struct s{
	int u, v, w;
};
vector<S>G[Max_n];
int fa[Max_n], block, ans;
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool cmp(s a, s b){
	return a.w > b.w;
}
int a(){
	vector<s>q;
	for(auto e : G[1]){
		q.push_back(s{1, e.v, e.w});
	}
	while(block != 1){
		sort(q.begin(), q.end(), cmp);
		int u = q[q.size()-1].u, v = q[q.size()-1].v, w = q[q.size()-1].w;
		q.pop_back();
		if(find(u) != find(v)){
			if(find(1) != find(v)){
				for(auto e : G[v]){
					q.push_back(s{v, e.v, e.w});
				}
			}else{
				for(auto e : G[u]){
					q.push_back(s{u, e.v, e.w});
				}
			}
			ans += w;
			fa[u] = fa[v];
			block--;
		}
	//	cout << block;
		
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= n; i++){
		cin >> u >> v >> w;
		G[u].push_back(S{v, w});
		G[v].push_back(S{u, w});
		fa[i] = i;
	}
	block = n;
	a();
	cout << ans;
	return 0;
}