#include<bits/stdc++.h>
using namespace std;
#define ll long long
//rerecycyclcl
//road
struct node{
	ll v,w;
};
ll n,m,k,u0,v0,w0,c[20],a[20][10010],vis[10010],dis[10010],ond[20],ans;
bool diik=1;
vector<node> adj[10010];
//ll youx[100100],lug=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u0>>v0>>w0;
		adj[u0].push_back({v0,w0});
		adj[v0].push_back({u0,w0});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)diik=0;
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)ond[i]=j;
		}
	}
	if(k==0){
		for(ll i=1;i<=n;i++){
			dis[i]=0x3f3f3f3f;
		}
		dis[1]=0;
		for(ll i=1;i<=n;i++){
			ll mm=0x3f3f3f3f,now;
			for(ll j=1;j<=n;j++){
				if(dis[j]<mm&&vis[j]==0){
					mm=dis[j];
					now=j;
				}
			}
			vis[now]=1;
			ans+=mm;
			for(ll j=0;j<adj[now].size();j++){
				dis[adj[now][j].v]=min(dis[adj[now][j].v],adj[now][j].w);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(diik){
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				if(ond[i]!=j){
					adj[ond[i]].push_back({j,a[i][j]});
					adj[j].push_back({ond[i],a[i][j]});
				}	
			}
		}
		for(ll i=1;i<=n;i++){
			dis[i]=0x3f3f3f3f;
		}
		dis[1]=0;
		for(ll i=1;i<=n;i++){
			ll mm=0x3f3f3f3f,now;
			for(ll j=1;j<=n;j++){
				if(dis[j]<mm&&vis[j]==0){
					mm=dis[j];
					now=j;
				}
			}
			vis[now]=1;
			ans+=mm;
			for(ll j=0;j<adj[now].size();j++){
				dis[adj[now][j].v]=min(dis[adj[now][j].v],adj[now][j].w);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
