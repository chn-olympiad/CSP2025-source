#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e5+5;

struct Edge{
	int u,v,w;
	bool consumed;
};
vector<Edge> g;

bool cmp(Edge& a, Edge& b){
	return a.w<b.w;
}

int fa[MAX];

int find(int u){
	if (fa[u] == u) return u;
	fa[u] = find(fa[u]);
	return fa[u];
}

int kruskal(int n){
	sort(g.begin(),g.end(),cmp);
	
	for (int i=1;i<=n;i++){
		fa[i] = i;
	}
	
	int ans = 0;
	for (Edge e:g){
		if (e.consumed) continue;
		int u = find(e.u);
		int v = find(e.v);
		if (u == v) continue;
		fa[u] = v;
		ans += e.w;
	}
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for (int i=0;i<m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w,0});
	}
	
	vector<vector<int>> towns(k);
	
	int a;
	for (int i=0;i<k;i++){
		for (int j=0;j<=n;j++){
			cin>>a;
			towns[i].push_back(a);
		}
	}
	
	int ans = 0;
	for (vector<int>& vec:towns){
		n++;
		ans += vec[0];
		for (int i=1;i<(int)vec.size();i++){
			g.push_back({n,i,vec[i],0});
		}
	}
	ans += kruskal(n);
	cout<<ans;
	return 0; 
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
