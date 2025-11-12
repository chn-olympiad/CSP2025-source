#include<bits/stdc++.h>
using namespace std;
const int N=1e3+15;
int n,m,k,maxx,a[25][N],dis[N][N];
void f(){
	for(int q=1;q<=n+k;q++){
		for(int i=1;i<=n+k;i++){
			if(dis[i][q]==1e9)continue;
			for(int j=1;j<=n+k;j++){ 
				if(dis[i][j]>dis[i][q]+dis[q][j]){
					dis[i][j]=dis[i][q]+dis[q][j];
				}
			}
		}
	}
	for(int i=1;i<n+k;i++){
		for(int j=i+1;j<=n+k;j++){
			maxx=max(maxx,dis[i][j]);
		}
	}
	return;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			dis[i][j]=1e9;
			if(i==j)dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		//if(a[i][0])qq++;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			dis[n+i][j]=dis[j][n+i]=min(dis[n+i][j],a[i][0]+a[i][j]);
			//if(j==1)dis[n+i][j]+=a[i][0],dis[j][n+i]+=a[i][0];
		}
	}
	f();
	cout<<maxx;
	return 0;
}//Ren5Jie4Di4Ling5%
