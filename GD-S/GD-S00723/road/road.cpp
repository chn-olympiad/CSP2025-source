#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[111],ans;
bool vis[1000101],flag=true;
struct Nove{
	int to,w;
};
struct side{
	int u,v,w;
	bool operator < (const side &A){
		return w<A.w;
	}
}a[1145141];
vector<Nove> G[1000101];
void Kruscal(){
	for(int i=1;i<=m;i++){
		if(vis[a[i].u]&&vis[a[i].v]){
			continue;
		}
		ans+=a[i].w;
		vis[a[i].u]=vis[a[i].v]=true;
//		cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<< endl;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		if(c[n+i]!=0){
			flag=false;
		}
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			G[n+i].push_back({j,w});
			G[j].push_back({n+i,w});
		}
	}
	if(flag&&k!=0){
		cout<<0;
		return 0;
	} 
	sort(a+1,a+m+1);
	Kruscal();
	cout<<ans;
	return 0;
}
