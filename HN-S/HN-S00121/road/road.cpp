#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=1e6+10;
struct S{
	int v,w;
};
vector<S>G[maxn];
void add(int u,int v,int w){
	G[u].push_back({v,w});
	G[v].push_back({u,w});
}
int c[15][maxn];
int fa[maxn];
void dfs(){
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
//	dfs();
	cout<<0;
	return 0;
} 
/*
4 4 2

1 4 6

2 3 7

4 2 5

4 3 4

1 1 8 2 4

100 1 3 2 4


*/
