#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,a[15][10005],vis[10005];
long long ans;
struct node{
	int w,v;
};
vector<node> g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back((node){w,v});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
			
		}
	}
	cnt=vis[1]=1;
	while(cnt<n){
		int u,vv,w=1e9;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(auto v:g[i]){
					if(v.w<w && !vis[v.v]){
						u=i;
						vv=v.v;
						w=v.w;
					}
				}
			}
		}
		ans+=w;
		cnt++;
		vis[vv]=1;
	}
	cout<<ans;
	return 0;
}
