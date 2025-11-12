#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,A=1,a[15],fa[10015];
int e[10015][10015];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
priority_queue<pair<int,pair<int,int> > > q,p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=n+k;i++) e[i][i]=0,fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[u][v]=e[v][u]=w;
		q.push({-w,{u,v}});
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];if(a[i]) A=0;
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			if(!a[i]) q.push({-w,{i+n,j}});
		}
	}
	if(k==0||A){
		while(!q.empty()){
			int w=-q.top().first;
			int u=q.top().second.first;
			int v=q.top().second.second;
			q.pop();
			if(find(u)==find(v)) continue;
			ans+=w,fa[find(u)]=find(v);
		}
		cout<<ans;
		return 0;
	}
	while(!q.empty()){
		int w=-q.top().first;
		int u=q.top().second.first;
		int v=q.top().second.second;
		q.pop();
		if(find(u)==find(v)) continue;
		ans+=w,fa[find(u)]=find(v);
	}
	cout<<ans;
	return 0;
}
