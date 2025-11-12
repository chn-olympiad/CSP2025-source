#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005],b[1005],c[1005],t[1005][1005],vis[1005],ans=1e9;
void dfs(int jz,int now,int cnt){
	if(cnt==n){
		ans=min(ans,jz);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(jz+t[now][i],i,cnt++);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+5;i++){
		for(int j=1;j<=n+5;j++)t[i][j]=1e8;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		t[a[i]][b[i]]=min(t[a[i]][b[i]],c[i]);
	}
	for(int i=1;i<=k;i++){
		int nc,p[1005];
		cin>>nc;
		for(int j=1;j<=n;j++)cin>>p[j];
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				t[j][k]=min(t[j][k],nc+p[j]+p[k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(0,i,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
