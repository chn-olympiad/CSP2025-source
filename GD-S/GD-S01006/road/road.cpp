#include<bits/stdc++.h>
using namespace std;
int n,m,k,mp[20000][20000],c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	int z=1;
	bool f=0;
	for(int i=1+n;i<=k+n;i++){
		cin>>c[z];
		if(c[z]!=0){
			f=1;
		}
		z++;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			mp[i][j]=w;
			mp[j][i]=w;
			if(w!=0){
				f=1;
			}
		}
	}
	for(int z=1;z<=n+k;z++){
		for(int i=1;i<=n+k;i++){
			for(int j=1;j<=n+k;j++){
				if(mp[i][j]>mp[i][k]+mp[k][j]){
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
	cout<<mp[1][n];
	return 0;
}
