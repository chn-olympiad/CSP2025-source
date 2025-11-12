#include<bits/stdc++.h>
using namespace std;
int n, m, k, vis[1000010], f[10010][10010], x[1000010], y[1000010], va[1000010], ans=INT_MAX;
void check(){
	int sum=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			f[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1; i<=m; i++){
		if(vis[i]==0){
			f[x[i]][y[i]]=va[i];
			sum+=va[i];
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	int fl=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(f[i][j]==0x3f3f3f3f){
				fl=1;
			}
		}
	}
	if(fl==0){
		ans=min(ans, sum);
	}
}
void dfs(int x){
	if(x>m){
		check();
		return ;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		x[i]=u;
		y[i]=v;
		va[i]=w;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

