#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,s=0;
	int u[1000002],v[1000002],w[1000002],a[12][10002],c[12],map[10002][10002],vis[10002][10002]={};
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		map[u[i]][v[i]]=w[i];
		vis[u[i]][v[i]]=1;
	}
	if(k!=0){
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int p=1;p<=n;p++){
				if(p!=i&&p!=j){
					if(vis[i][p]==1&&vis[p][j]==1){
						if(vis[i][j]==0){
							vis[i][j]=1;
							map[i][j]=map[i][p]+map[p][j];
						}
						else{
							if(map[i][j]>map[i][p]+map[p][j]){
								map[i][j]=map[i][p]+map[p][j];
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s+=map[i][j];
		}
	}
	cout<<s;
	return 0;
}
