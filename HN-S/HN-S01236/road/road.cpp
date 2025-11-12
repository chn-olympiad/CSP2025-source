#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10009][10009];
ll g[10009][10009];
ll n,m,k;
ll c[19];
ll b[19][10009];
ll oo=0x3f3f3f;
ll sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			g[i][j]=oo;
		}
	}
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>b[i][j];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll x=1;x<=n;x++){
				if(i==j||j==x||i==x)continue;
				if(g[i][j]&&g[i][x]&&g[j][x]&&g[i][x]+g[x][j]<g[i][j]){
					g[i][j]=g[i][x]+g[x][j];
					//cout<<i<<"-->"<<j<<"="<<i<<"-->"<<x<<"-->"<<j<<endl;
				}
			}
			for(ll x=1;x<=k;x++){
				if(i==j)continue;
				if(b[k][i]+c[i]+b[k][j]<g[i][j]){
					//cout<<i<<"-->"<<j<<"="<<i<<"-->"<<"c"<<x<<"-->"<<j<<endl;
					g[i][j]=b[k][i]+c[i]+b[k][j];
				}
			}
		}
	}
	for(ll i=2;i<=n;i++){
		//cout<<1<<"-->"<<i<<" "<<g[1][i]<<endl;
		sum+=g[1][i];
	}
	cout<<sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
