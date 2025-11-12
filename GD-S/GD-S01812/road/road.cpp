#include<iostream>
using namespace std;
long long n,m,k,l[1005][1005],u,v,w,zs=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			l[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		l[u][v]=w;l[v][u]=w;
	}
	for(int i=1;i<=k;i++){	
		cin>>u;
		zs+=u;
		for(int j=1;j<=n;j++){
			cin>>w;
			l[j][i+n]=w;l[i+n][j]=w;
		}
	}	
	for(int t=1;t<=n+k;t++){
		for(int i=n+k;i>=1;i--){
			for(int j=1;j<=i;j++){
				if(l[i][t]!=-1&&l[t][j]!=-1&&l[i][j]!=-1&&l[i][t]+l[t][j]<=l[i][j]){
					l[i][j]=-1;l[j][i]=-1;
				}
			}
		}
	}
	for(int i=n+k;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(l[i][j]!=-1){
				zs+=l[i][j];
			}	
		}
	}	
	cout<<zs;
	return 0;
}
/*
3 2 2
1 2 4
1 3 5
0 2 99 1
0 1 1 1
*/
