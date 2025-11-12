#include<bits/stdc++.h>
#define x first
#define y second.first
#define z second.second
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll> > node;
const ll N=1e4+10;
ll fa[N],n,m,k,ans=1e9,a[N],g[20][N];
priority_queue<node>pq,q;
ll find(ll x){
	return(fa[x]==x?x:fa[x]=find(fa[x]));
}
void work(ll S){
	for(ll i=1;i<=n+k;i++) fa[i]=i;
	ll res=0;
	q=pq;
	for(ll i=1;i<=k;i++)
		if(S&(1<<i-1)){
			res+=a[i];
			for(ll j=1;j<=n;j++)
				q.push({-g[i][j],{j,n+i}});
		}
	while(!q.empty()){
		ll w=q.top().x,u=q.top().y,v=q.top().z;
		q.pop();
		if(find(u)==find(v)) continue;
		res-=w;
		fa[fa[u]]=fa[v];
//			for(int i=1;i<=n+k;i++) cout<<fa[i]<<' ';
//			cout<<'\n';
	}
//		cout<<res;
//		cout<<'\n';
	ans=min(ans,res);
}
void solve(){
	cin>>n>>m>>k;
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		pq.push({-w,{u,v}});
	}
	for(ll i=1;i<=k;i++){
		cin>>a[i];
		for(ll j=1;j<=n;j++) cin>>g[i][j];
	}
	for(ll i=0;i<(1<<k);i++) work(i);
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
