#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	int l[n+1][n+1],b[k+1][n+2];
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		l[u][v]=w;
		l[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}int g=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l[i][j]=min(l[i][j],b[g][1]+b[g][i]+b[g][j]);
			if(g!=2){
				g++;
			}else{
				g=1;
			}
		}
	}int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=l[i][j];
		}
	}cout<<sum/2;
} 
