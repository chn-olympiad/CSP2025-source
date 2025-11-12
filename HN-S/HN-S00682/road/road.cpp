#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10010];
struct edge{
	ll to,srt,w;
}e[6000010];
ll cnt;
void add(ll x,ll y,ll w){
	e[++cnt].to=y;
	e[cnt].srt=x;
	e[cnt].w=w;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[10010];
int find(ll x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
bool merge(ll x,ll y){
	ll fx=find(x),fy=find(y);
	if(fx==fy){
		return false;
	}
	else{
		fa[fx]=fy;
		return true;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
		for(ll j=1;j<=n;j++){
			ll a;
			cin>>a;
			add(c,i,a);
			add(i,c,a);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	ll ans=0,sum=0;
	for(int i=1;i<=cnt;i++){
		if(merge(e[i].srt,e[i].to)){
			ans+=e[i].w;
			sum++;
		}
		if(sum==n+k-1){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
