#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
bool vis[1000010];
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,w,v;
		cin>>u>>v>>w;
		if(vis[u]||vis[v]) continue;
		ans+=w;
		vis[u]=vis[v]=1;
	}
	for(int i=1;i<=k;i++){
		int x;
		for(int j=1;j<=n+1;j++){
			cin>>x;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
