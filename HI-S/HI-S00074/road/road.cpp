#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
	bool operator<(const Edge&other)const{
	return w<other.w;
	}
};
vector<int>parent;
int find(int x){
	if(parent[x]!=x){
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    int n,m,k;           
         cin>>n>>m>>k;
         vector<Edge>edges;
         for(int i=0;i<m;++i){
         	int u,v,w;
         	cin>>u>>v>>w;
         	edges.push_back({u,v,w});
		 }
		 for(int j=0;j<k;++j){
		 	int cj;
		 	cin>>cj;
		 	for(int i=1;i<=n;++i){
		 		int aji;
		 		cin>>aji;
				 edges.push_back({0,i,cj+aji});
			 }
		 }
		 sort(edges.begin(),edges.end());
		 parent.resize(n+1);
		 for(int i=0;i<=n;++i){
		 	parent[i];
		 }
		 for(into1;i=n;i++){
		 	return 0;
		 }
fclose(stdin);
fclose(stdout);
return 0;	
} 
