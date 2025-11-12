#include<bits/stdc++.h>
using namespace std;
struct DSU{
	int pa[1000001];
	void init(){
		for(int i=0;i<1000001;i++){
			pa[i]=i;
		}
	}
	size_t find(size_t tar){
		if(pa[tar]==tar){
			return tar;
		}
		return pa[tar]=find(pa[tar]);
	}
	void unite(size_t a,size_t b){
		pa[find(a)]=pa[find(b)];
	}
}dsu;
struct edge{
	int u,v,w;
	bool operator<(edge x)const{
		return w>x.w;
	}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue<edge>q;
	dsu.init();
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	int res=0;
	while(!q.empty()){
		if(dsu.find(q.top().u)!=dsu.find(q.top().v)){
			res+=q.top().w;
			dsu.unite(q.top().u,q.top().v);
		}
		q.pop();
	}
	cout<<res;
	
	return 0;
}
