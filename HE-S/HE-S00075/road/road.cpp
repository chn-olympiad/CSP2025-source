#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[11000][11000],vis[10001],ans=1e9;
void dfs(int l,int mon,int sum){
	if(sum==n){
		ans=min(ans,mon);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[l][i]>=0&&vis[i]==0){
			vis[i]=1;
			dfs(i,mon+a[l][i],sum++);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=-1;
		}
	}
	cin>>n>>m>>k;
	int u,v,w,c;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=m;i<=m+k;i++){
		cin>>c;
		int b[10001]={};
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=i;k<=n;k++){
				a[j][k]=b[j]+b[k]+c;
				a[k][j]=b[j]+b[k]+c;
			}
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,0,1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
