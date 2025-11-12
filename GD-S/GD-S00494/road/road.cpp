#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct edge{
	ll u,v,w;
};
vector<edge>g;
ll n,k,m,vis[15],c[15],fa[10100],ans=LLONG_MAX;
ll fd(ll x){return fa[x]==x?fa[x]:fa[x]=fd(fa[x]);}
bool cmp(edge x,edge y){return x.w<y.w;}
void kru(ll cnt,ll sum){
	for(edge i:g){
		ll u=i.u,v=i.v,w=i.w;
		if(u>n)if(vis[u-n])continue;
		if(v>n)if(vis[v-n])continue;
		u=fd(u);v=fd(v);
		if(u==v)continue;
		cnt--;
		fa[u]=v;
		sum+=w;
		if(sum>ans)return;
		if(cnt==1ll)break;
	}
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,g.push_back({u,v,w}),g.push_back({v,u,w});
	ll f=0;
	for(ll i=1;i<=k;i++){
		cin>>c[i];vis[i]=0;
		if(c[i]>0)f=1;
		ll ff=1;
		for(ll j=1,x;j<=n;j++)
			cin>>x,g.push_back({n+i,j,x}),g.push_back({j,n+i,x}),ff=min(ff,x);
		f=ff;
	}
	sort(g.begin(),g.end(),cmp);
	if(!f){
		for(ll j=1;j<=n+k;j++)fa[j]=j;
		kru(n+k,0);
		cout<<ans;
		return 0;
	}
	for(ll i=0;i<(1<<k);i++){
		ll cnt=n,sum=0;
		for(ll j=1;j<=k;j++)vis[j]=1;
		for(ll j=1;j<=n+k;j++)fa[j]=j;
		for(ll j=k;j>=1;j--)if(i&(1<<(j-1)))cnt++,sum+=c[j],vis[j]=0;
		kru(cnt,sum);
	}
	cout<<ans;
	return 0;
}
//O(2^km)
