#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<ll,ll>
#define ve vector<ll>
#define mid ((l+r)>>1)
#define lx (x<<1)
#define rx (x<<1|1)
using namespace std;
const ll N=1e4+12,M=2e6+2;
ll n,m,k,ans,c[N],f[1024][N],g[N];
struct node{ll x,y,z,t;}e[M];
ll find(ll s,ll x){
	return x==f[s][x]?x:f[s][x]=find(s,f[s][x]);
}
ll merg(ll s,ll x,ll y){
	if((x=find(s,x))!=(y=find(s,y)))
		return f[s][x]=y,1;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,ans=1e14;
	for(ll i=1,x,y,z;i<=m;i++)
		cin>>x>>y>>z,e[i]={x-1,y-1,z,k};
	for(ll i=0,x;i<k;i++){
		cin>>x;
		for(ll s=0;s<(1<<k);s++)g[s]+=(s>>i&1?x:0);
		for(ll j=0;j<n;j++)cin>>x,e[++m]={i+n,j,x,i};
	}
	for(ll s=0;s<(1<<k);s++)
		for(ll i=0;i<n+k;i++)f[s][i]=i;
	sort(e+1,e+m+1,[](node x,node y){return x.z<y.z;});
	for(ll i=1;i<=m;i++){
		node v=e[i];
		ll x=v.x,y=v.y,z=v.z,t=v.t;
		if(find(0,x)==find(0,y))continue;
		if(t<k&&find(1<<t,x)==find(1<<t,y))continue;
		for(ll s=0;s<(1<<k);s++)
			if(t==k||s>>t&1)g[s]+=(merg(s,x,y)?z:0);
	}
	for(ll s=0;s<(1<<k);s++)ans=min(ans,g[s]);
	cout<<ans;
	return 0;
}
