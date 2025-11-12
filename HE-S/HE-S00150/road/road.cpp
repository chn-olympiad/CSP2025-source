#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,ans=1e9,cnt,mi=1e9;
int mp[10005][10005],l[10005],vis[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
		mp[u][v]=w;
		mp[v][u]=w;
		//vis[u][v]=1;
		//vis[v][u]=1;
	}
//	for(int i=1;i<=n;i++){
//	    for(int j=2;j<=n;j++){
//	    	if(vis[i][j]==1&&vis[i][j+1]=1){
//	    		vis[j][j+1]=1;
//	    		vis[j+1][j]=1;
//			}
//		}
//	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>l[j];
			mp[j][n+1]=l[j];
			mp[n+1][j]=l[j];
		}
		for(int k=1;k<=n;k++){
			for(int p=1;p<=n+1;p++){
				if(mp[k][p]!=0){
					mi=min(mi,mp[k][p]);
				}
			}
			cnt+=mi;
			mi=1e9;
		}
		ans=min(ans,cnt+c);
	}
	cout<<ans;
	return 0;
}

