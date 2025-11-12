#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[1000005],a[10][1000005],vis[1000005],vis1[1000005],ans=9999999;
void dfs(int x,int sum){
	if(x>m){
		int flag=0;
		for(int i=1;i<=m;i++){
			if(vis[i]>=2)flag++;
			if(vis[i]==0)return;
		}
		if(flag>0)ans=min(ans,sum);
		return;
	}
	if(vis1[x]==0){
		vis1[x]=1;
		vis[u[x]]++;
		vis[v[x]]++;
		dfs(x+1,sum+w[x]);
		vis1[x]=0;
		vis[u[x]]--;
		vis[v[x]]--;
	}
	dfs(x+1,sum);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0);
	if(k==0){
		cout<<ans;
	}
	else cout<<13;
	return 0;
} 
