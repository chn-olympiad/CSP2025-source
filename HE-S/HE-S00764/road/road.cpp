#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+25;
ll n,m,k,x,y,z,c[20],a[20][N];
ll ans,cnt,vis[N],f[N];
struct stu{
	ll u,v,w;
	bool operator<(const stu &z){
		return w<z.w;
	}
}d[N];
ll fin(ll x){
	return (f[x]==x?x:f[x]=fin(f[x]));
}
void hb(ll x,ll y){
	x=fin(x),y=fin(y);
	if(x==y) return ;
	f[y]=x;
	return ;
}
void dfs(ll m){
	for(ll i=1;i<=m;i++){
		ll x=fin(d[i].u),y=fin(d[i].v);
		if(x==y) continue;
		f[y]=x;
		cnt++;
		ans+=d[i].w;
		if(cnt==n-1) break;
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n+k;i++) f[i]=i;
	for(ll i=1;i<=m;i++){
		cin>>d[i].u>>d[i].v>>d[i].w;
	}
	sort(d+1,d+1+m);
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			d[m++].u=i+n;
			d[m].v=j;
			d[m].w=a[i][j];
		}
	}
	dfs(m);
	cout<<ans;
	return 0;
}
