#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	bool operator<(const Edge& other) const{
		return w<other.w;
	}
};
vector<int>parent;
int find(int x){
	return parent[x]==x?x:parent[x]=find(parent[x]);
}
bool unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return false;
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<Edge>edges;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}
	for(int i=0;i<k;i++){
		int c;cin>>c;
		int mc=1e9;
		for(int j=0;j<n;j++){
			int a;cin>>a;
			mc=min(mc,a);
		}
		for(int j=0;j<n;j++){
			edges.push_back({n+1+i,mc});
		}
	}
	int tot=n+k;
	parent.resize(tot+1);
	iota(parent.begin(),parent.end(),0);
	sort(edges.begin(),edges.end());
	long long ans=0;
	int cnt=0;
	for(const Edge& e : edges){
		if(unite(e.u,e.v)){
			ans+=e.w;
			cnt++;
			if(cnt==tot-1)break;
		}
	}
	cout<<ans;
	return 0;
}
