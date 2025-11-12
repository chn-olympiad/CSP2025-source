#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
typedef long long ll;
ll t,n,m,k;
ll dist[N][N];
ll sum;
ll a[N][N];


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=1e10;
		}
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v;
		ll w;
		cin>>u>>v>>w;
		dist[u][v]=dist[v][u]=w;
	}
	/*for(int i=1;i<=k;i++){
		cin>>vill[i][0];
		for(int j=1;j<=n;j++){
			cin>>vill[i][j];
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int e=1;e<=n;e++){
				dist[j][i]=dist[i][j]=min(dist[i][j],dist[i][e]+dist[e][j]);
				//cout<<dist[i][j]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dist[i][j]!=1e10) sum=max(sum,dist[i][j]);
		}
	}
	cout<<sum;
	return 0;
} 
//Ren5Jie4Di4Ling5%

