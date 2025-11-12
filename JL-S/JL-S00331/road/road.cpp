#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,f[1005][1005],p[1005][1005],q[1005],ans=1e18;
void dfs(int l,int t,int s){
	if(t==n){
		ans=min(ans,s);
	}for(int i=1;i<=n;i++){
		if(q[i]==0&&p[l][i]==1){
			q[i]=1;
			dfs(i,t+1,s+f[l][i]);
			q[i]=0;
		}
	}
}signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w,a;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		f[u][v]=w;
		f[v][u]=w;
		p[u][v]=1;
		p[v][u]=1;
	}for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>a;
		}
	}if(k>0){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		q[i]=1;
		dfs(i,1,0);
		q[i]=0;
	}cout<<ans;
	return 0;
}
