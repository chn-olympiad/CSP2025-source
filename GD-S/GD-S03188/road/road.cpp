#include<bits/stdc++.h>
using namespace std;
int n,m,k,id;
int ans=0;
struct Adge{
	int u,v,w;
} a[9000006];
int fa[9000006],c[15],e[15][9000006];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void init(){
	for(int i=1;i<=n+k+1;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	init();
	while(!pq.empty()){
		int u=a[pq.top().second].u,v=a[pq.top().second].v,w=pq.top().first;
		pq.pop();
		u=find(fa[u]),v=find(fa[v]);
		if(u==v) continue;
		ans+=w;
		fa[u]=v;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[++id].u>>a[id].v>>a[id].w;
		pq.push({a[id].w,id});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			a[++id].u=i+n;
			a[id].v=j;
			cin>>a[id].w;
			pq.push({a[id].w,id});
		}
	}
	kruskal();
	cout<<ans;
	return 0;
} 
