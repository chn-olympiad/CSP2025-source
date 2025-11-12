#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,a[10014][10014],b[10],dp[10014],c[10014],c1[10014],vis[10014];
vector<int>V[10004];
bool cmp(){
	for(int i=1;i<=n;i++){
		if(dp[i]==1000000001){
			return 0;
		}
	}
	return 1;
}
void dfs(int x){
	if(cmp()){
		return ;
	}
	int z=0,h;
	for(int i=0;i<V[x].size();i++){
		int nt=V[x][i];
		if(vis[i]=1)continue;
		int s1=dp[nt];
		dp[nt]=min(dp[nt],dp[x]+a[x][nt]);
		if(s1!=dp[nt]){
			c[nt]=a[x][nt];
			c1[nt]=x;
		}
		int z1=z;
		z=min(a[x][nt],z);
		if(z1!=z)h=nt;
	}
	ans+=c[h];
	c[h]=0;
	c1[h]=0;
	vis[x]=1;
	dfs(h);
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	a[u][v]=w;
    	a[v][u]=w;
    	V[u].push_back(v);
    	V[v].push_back(u);
    	dp[i]=1000000001;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
		int w;
		cin>>w;
    	a[j][i+n]=w+b[i];
    	a[i+n][j]=w+b[i];
    	V[i+n].push_back(j);
    	V[j].push_back(i+n);
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		if(vis[i]!=1){
			ans+=c[i];
		}
	}
	for(int i=1+n;i<=n+k;i++){
		if(vis[i]==1){
			ans+=b[i-n];
			for(int j=1;j<=n;j++){
				if(c1[j]==i){
					ans-=b[i-n];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
