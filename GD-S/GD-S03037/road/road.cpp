#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
	bool operator<(const edge& other)const{
		return w<other.w;
	}
};
struct unionfind{
	vector<int> parent;
	unionfind(int n){
		parent.resize(n);
		for(int i=0;i<n;i++){
			parent[i]=i;
		}
	}
	int find(int x){
		if(parent[x]!=x) parent[x]=find(parent[x]);
		return parent[x];
	}
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x!=y) parent[y]=x;
	}
	
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<edge> edges;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u-1,v-1,w});
	}
	for(int i=0;i<k;i++){
		int p;
		cin>>p;
		edges.push_back({n+1,n+i,p});
		for(int j=0;j<n;j++){
			int q;
			cin>>q;
			edges.push_back({j,n+i,q});
		}
	}
	sort(edges.begin(),edges.end());
	unionfind uf(n+k);
	long long totalcost=0;
	int cityconnected=0; vector<bool> iscityconnected(n,false);
	for(vector<edge>::iterator it=edges.begin();it!=edges.end();it++){
		int u=it->u;
		int v=it->v;
		int w=it->w;
		int root_u=uf.find(u);
		int root_v=uf.find(v);
		if(root_u!=root_v){
			uf.unite(u,v);
			totalcost+=w;
			if(u<n and !iscityconnected[u]){
				iscityconnected[u]=true;
				cityconnected++;
			}
			if(v<n and !iscityconnected[v]){
				iscityconnected[v]=true;
				cityconnected++;
			}
			if(cityconnected==n){
				break;
			}
		}
		cout<<totalcost;
	}
}
