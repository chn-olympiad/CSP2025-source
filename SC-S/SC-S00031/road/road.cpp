#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll a[1005][1005];
ll b[1005][1005];
bool f[1005];
ll u,v,w;
ll c;
ll t[1000005];
ll dis[1005];
ll jc;
void dijsktra(){
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > que;
	for(que.push(make_pair(0,1));!que.empty();){
		ll u=que.top().second,d=que.top().first;
		que.pop();
		if(dis[u]!=d) continue;
		for(ll i=1;i<=n;i++){
			if(dis[i]>a[u][i]+d){
				dis[i]=a[u][i]+d;
				que.push(make_pair(dis[i],i));
			}
		}
	}
}
ll mi=INT_MAX;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(ll i=2;i<=n;i++){
		dis[i]=INT_MAX;
	}
	for(ll i=1;i<=k;i++){
		cin>>c;
		mi=min(mi,c);
		for(ll j=1;j<=n;j++){
			cin>>t[j];
		}
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(t[j]+t[k]<=a[j][k]||a[j][k]==0){
					a[j][k]=t[j]+t[k];
				}
			}
		}
	}
	dijsktra();
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans+mi;
	return 0;
}