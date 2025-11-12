#include<bits/stdc++.h>
#define ll long long
#define M 1001000
#define N 10100
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int n,m,k;
int f[N];
pair<ll,pair<int,int>> adj[M];
queue<pair<ll,pair<int,int>>> q;
inline int find(int fa){
	if(f[fa]==fa){
		return fa;
	}
	return find(f[fa]);
}
ll sum=0;
void solve(){
	for(int i=1;i<=m;i++){
		int u=adj[i].se.fi;
		int v=adj[i].se.se;
		int fau=find(u);
		int fav=find(v);
		if(fau!=fav){
			f[fau]=v;
			q.push(adj[i]);
			sum+=adj[i].fi;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		adj[i]=mp(w,mp(u,v));
	}
	sort(adj+1,adj+m+1);
	solve();	
	cout<<sum;
	return 0;
}