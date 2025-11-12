#include<bits/stdc++.h>
using namespace std;
const int N= 1e6+5;
struct node{
	int u,v;
	int edge;
};
int n,m,k,c[15][N],f[(int)1e4+5];
vector<node>g;
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx==ry)return;
	f[rx]=ry;
}
int cmp(node a,node b){
	return a.edge<b.edge;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		sort(g.begin(),g.end(),cmp);
		int ans=0;
		for(int i=0;i<g.size();i++){
			int u=g[i].u;
			int v=g[i].v;
			if(find(u)==find(v))continue;
			merge(u,v);
			ans+=g[i].edge;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
} 
