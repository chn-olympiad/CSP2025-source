#include<bits/stdc++.h>
const int N=1e4+3;
using namespace std;

struct node{
	int v, w;
}a;
int n, m, k, maxx=0, f[N];
bool xt[N];
vector<node>e[N];
bool cmp(node a, node b){
	if(a.w==b.w)return a.v>b.v;
	else return a.w<b.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(xt, 0, sizeof(0));
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1; i<=m; i++){
			int u, v, w;
			cin>>u>>v>>w;
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}
		for(int i=1; i<=n; i++){
			sort(e[i].begin(), e[i].end(), cmp);
		}
		for(int i=1; i<=n; i++){
			cout<<maxx<<"\n";
			if(xt[i]==1)continue;
			maxx+=e[i][0].w;
			if(e[e[i][0].v][0].w==e[i][0].w)xt[e[i][0].v]=1;
		}
		cout<<maxx;
	}
	
	return 0;
}
/*
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}

bool al(int u,int v){
	int fu=f[u], fv=find(v);
	if(fu!=fv){
		f[u]=find(v);
		f[v]=find(u);
	}
	return 1;
}*/

		
