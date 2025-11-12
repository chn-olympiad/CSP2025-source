#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct Edge{
	int u,v,w;
};
int fa[100005];
int find(int x){
	if(fa[x]==0)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<Edge>edges;
 	for(int i=0;i<m;i++)
 	{
 		int u,v,w;
 		cin>>u>>v>>w;
 		edges.push_back({u,v,w});
 		edges.push_back({v,u,w});
	}
	
 	sort(edges.begin(),edges.end(),[](const auto&x,const auto&y){
 		return x.w<y.w;
	});
	int cnt=0,res=0;
	auto ptr=edges.cbegin();
	while(cnt!=n-1){
		int u=find(ptr->u);
		int v=find(ptr->v);
		int w=ptr->w;
		ptr++;
		if(u==v){
			continue;
		}
		fa[u]=v;
		cnt++,res+=w;
	}
	cout<<res;
	return 0;
}

