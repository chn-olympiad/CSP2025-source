#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,k,ans;
int u,v,c,***dis;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	dis=new int**[n+k+1];
	for(int j=0;j<=n;++j){
		dis[j]=new int*[n+k+1];
		for(int i=0;i<=n+k+1;++i){
			dis[j][i]=new int[2];
			dis[j][i][0]=INT_MAX;
			dis[j][i][1]=0;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		cin>>dis[u][v][0];
		dis[v][u][0]=dis[u][v][0];
		dis[u][v][1]=dis[v][u][1]=1;
	}
	for(int i=1;i<=k;++i){
		cin>>c;
		for(int j=1;j<=n;++j){
			u=j;
			v=n+i;
			cin>>dis[u][v][0];
			dis[u][v][0]+=c;
			dis[v][u][0]=dis[u][v][0];
			dis[u][v][1]=dis[v][u][1]=1;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n+k;++j){
			for(int k=1;k<=n+k;++k){
				if(dis[i][j][0]>(dis[i][k][0]+dis[k][j][0])){
					dis[i][j][0]=dis[i][k][0]+dis[k][j][0];
					dis[j][i][0]=dis[i][j][0];
					dis[u][v][1]=dis[v][u][1]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(dis[i][j][1]){
				ans+=dis[i][j][0];
			}
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
