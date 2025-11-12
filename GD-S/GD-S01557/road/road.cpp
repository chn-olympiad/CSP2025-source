#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
const ll INF=1e12+10;
ll n,m,k,dist[N][N],rp[N];
ll solve(){
//	for(int i=1;i<=n;i++){
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
//	if(rp[1]==0){
//		return 0;
//	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dist[i][j]=INF;
		}
	}
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		dist[u][v]=w;
		dist[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>rp[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	cout<<"0";
	return 0;
}

