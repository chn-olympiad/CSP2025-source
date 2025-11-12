#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int n,m,k,fa[N],bf,jl,vis[N];
long long ans=0;
struct edge{
	int v,w;
};
vector<edge>e[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]); 
}
long long krus(int s){
	int sum=n-1;
	while(sum--){
		for(auto ed:e[s]){
			jl=1e9;
			if(find(ed.v)==find(s))continue; 
			for(auto to : e[ed.v]){
				if(find(to.v)==find(s)){
					if(jl>to.w){
						jl=to.w;
					}
				}
			}
			ans+=jl;
			fa[find(ed.v)]=find(s);
			s=ed.v;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1,w,c;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>w;
		}
	}
	cout<<krus(1);
	return 0;
}