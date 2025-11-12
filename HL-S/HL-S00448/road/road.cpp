#include<bits/stdc++.h>

using namespace std;
//在写这道题时google小恐龙达到了15000pts，望周知 
int n,m,u[100005],v[100005],w[100005],k,c[50],a[10][10005],mp[1005][1005],vis[1005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		mp[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			a[i][j]+=c[i]; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]&&(!vis[i]||!vis[j])){
				ans+=mp[i][j];
				vis[i]=1,vis[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
