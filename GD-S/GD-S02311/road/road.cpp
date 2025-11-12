#include<bits/stdc++.h>
#define ll long long
#define N 12009
#define M 1200009
using namespace std;
struct node{
	ll u,v,w;
}s[M],g[N];
ll c[12],a[12][N],cnt,ans;
bool cmp(node x,node y){return x.w<y.w;}
ll fa[N],vis[N];
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=1;i<=m;i++)
		scanf("%lld%lld%lld",&s[i].u,&s[i].v,&s[i].w);
	sort(s+1,s+1+m,cmp);
	for(ll i=1;i<=m;i++){
		ll u=s[i].u,v=s[i].v,w=s[i].w;
		ll fa1=find(u),fa2=find(v);
		if(fa1==fa2)continue;
		fa[fa1]=fa2;
		g[++cnt]={u,v,w};
		ans+=w;
		if(cnt>=n-1)break;
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			g[++cnt]={i+n,j,a[i][j]};
		}
	}
	sort(g+1,g+1+cnt,cmp); 
	for(ll i=0;i<(1<<k);i++){
		ll sum=0,num=0,mu=n;
		for(ll j=1;j<=k;j++)vis[j]=0;
		for(ll j=0;j<k;j++)
			if((i>>j)&1ll){
				sum+=c[j+1];
				vis[j+1]=1;
				mu++;
			}
		for(ll j=1;j<=n+k;j++)fa[j]=j;
		for(ll j=1;j<=cnt;j++){
			ll u=g[j].u,v=g[j].v,w=g[j].w;
			if(u>n&&vis[u-n]!=1)continue;
			ll fa1=find(u),fa2=find(v);
			if(fa1==fa2)continue;
			fa[fa1]=fa2;
			sum+=w;
			num++;
			if(num==mu-1)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
