#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+50;
ll n,m,k;
ll edge[N][N];
ll c[N];
ll a[N];
ll sum;
ll vis[N];
ll dij(ll x,ll sum){
	ll minn=1e9+10,mini;
	for(ll i=0;i<n;i++){
		if(i==x)continue;
		if(minn>edge[x][i]&&!vis[i]){
			mini=i;
			minn=edge[x][i];
		}
	}
	if(minn==1e9+10)return sum;
	ll y=x+1;
	sum+=edge[x][mini];
	vis[mini]=1;
	return dij(mini,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(edge,0x3f3f3f3f,N*N);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		edge[u][v]=edge[v][u]=w;	
	}
	ll ans=0;
	for(ll i=0;i<k;i++){
		cin>>c[i];
		for(ll j=0;j<n;j++){
			cin>>a[j];
		}
		for(ll j=0;j<n;j++){
			for(ll k=0;k<n;k++){
				if(k==j)continue;
				if(edge[k][j]>a[j]+a[k]+c[i]){
					ans+=c[i];
					c[i]=0;
				}
			}
			for(ll k=0;k<n;k++){
				if(k==j)continue;
				edge[j][k]=edge[k][j]=min(edge[k][j],a[j]+a[k]);
			}
		}
	}
	
	vis[0]=1;
	cout<<dij(0,0)+ans;
	return 0;
} 
