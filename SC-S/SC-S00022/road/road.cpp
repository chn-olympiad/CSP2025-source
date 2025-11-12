#include<bits/stdc++.h>
using namespace std;
int ds[1000500];
int find(int x){
	if(ds[x]!=x){
		ds[x]=find(ds[x]);
	}
	return ds[x];
}
struct node{
	int w,u,v;
};
vector<node> g;
bool cmp(node p1,node p2){
	return p1.v<p2.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	bool ttt=true;
	for(int i=1;i<=n;i++){
		ds[i]=i;
		int u,w,v;
		cin>>u>>w>>v;
		node xx;
		xx.w=w;
		xx.u=u;
		xx.v=v;
		g.push_back(xx);
		xx.w=u;
		xx.u=w;
		g.push_back(xx);
		if(v!=0){
			ttt=false;
		}
	}
	if(ttt){
		cout<<0;
		return 0;
	}
	sort(g.begin(),g.end(),cmp);
	int ans=0;
	for(int i=0;i<g.size();i++){
		if(find(g[i].w)!=find(g[i].u)){
			ds[g[i].u]=find(g[i].w);
			ans+=g[i].v;
		}
	}
	cout<<ans;
	return 0;
}