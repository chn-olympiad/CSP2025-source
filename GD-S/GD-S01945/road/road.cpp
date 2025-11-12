#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u,v,w,c[21],a[21][10010],ans,tot,fl;
ll vis[10010],visk[21];
struct nod{
	ll pos,dis;
};
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
ll mp[10010][10010],dis[10010][10010];
void dijk(ll s){
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	for(ll i=1;i<=n;i++){
		if(mp[s][i]){
			dis[s][i]=mp[s][i];
			q.push(make_pair(mp[s][i],i));
		}
	}
	while(!q.empty()){
		pair<ll,ll> p=q.top();
		q.pop();
		vis[p.second]=1;
		for(ll i=1;i<=n;i++){
			if(!vis[i]&&mp[p.second][i]){
				if(!dis[s][i]&&dis[s][i]<dis[s][p.second]+mp[p.second][i]){
					dis[s][i]=dis[s][p.second]+mp[p.second][i];
					q.push(make_pair(mp[p.second][i],i));
				}
			}
		}
	}
}
void bfs(ll s){
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	for(ll i=1;i<=n;i++){
		if(mp[s][i]){
			q.push(make_pair(mp[s][i],i));
		}
	}
	while(!q.empty()){
		pair<ll,ll> p=q.top();
		q.pop();
		if(!vis[p.second]){
//			cout<<p.second<<" "<<p.first<<endl;
			ans+=p.first;
		}
		vis[p.second]=1;
		for(ll i=1;i<=n;i++){
			if(!vis[i]&&mp[p.second][i]) q.push(make_pair(dis[p.second][i],i));
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[v][u]=w;
		mp[u][v]=w;
	}
	for(ll i=1;i<=n;i++){
		dijk(i);
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
		fl=tot=0;
		for(ll j=1;j<=n;j++){
			for(ll jjj=1;jjj<=j;jjj++){
				if(a[i][j]+a[i][jjj]<dis[j][jjj]){
					tot+=dis[j][jjj]-a[i][j]+a[i][jjj];
					if(tot>c[i]){
						fl=1;
						break;
					}
				}
			}
			if(fl){
				break;
			}
		}
		if(fl){
			ans+=c[i];
			for(ll j=1;j<=n;j++){
				for(ll jjj=1;jjj<=j;jjj++){
					if((!mp[j][jjj])||a[i][j]+a[i][jjj]<mp[j][jjj]){
						mp[j][jjj]=a[i][j]+a[i][jjj];
						mp[jjj][j]=a[i][j]+a[i][jjj];
					}
				}
			}			
		}

	}
	bfs(1);
	cout<<ans;
	return 0;
}

