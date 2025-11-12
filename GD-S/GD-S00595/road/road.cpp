#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,k,fa[10010],c[20],xc[20][10010],mi[20],ans=1000000000000000;
struct sd{
	ll u,v,w;
}s[2001000],s2[2001000];
bool vis[2001000];
bool cmp(sd a,sd b){
	return a.w<b.w;
}
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	fa[find(x)]=fa[find(y)];
}
void solve0(){
	for(ll i=1;i<=m;i++){
		s2[i]=s[i];
	}
	for(ll i=1;i<=n;i++)fa[i]=i;
	ll g=n;
	ll sum=0;
	sort(s2+1,s2+1+m,cmp);
	ll tot=0;
	for(ll i=1;i<=m;i++){
		if(g==1)break;
		ll u=s2[i].u,v=s2[i].v,w=s2[i].w;
		if(find(u)!=find(v)){
			fa[find(u)]=fa[find(v)];sum+=w;g--;s[++tot]=s2[i];
		}
	}
	ans=min(ans,sum);m=tot;
	return;
}
void solve(ll w){
	for(ll i=1;i<=m;i++){
		s2[i]=s[i];
	}
	ll tot=m;
	ll sum=0;
	for(ll i=1;i<=k;i++){
		if(w&(1<<i-1)){
			sum+=c[i]+xc[i][mi[i]];
			for(ll j=1;j<=n;j++){
				sd p;p.u=mi[i];p.v=j;p.w=xc[i][j];s2[++tot]=p;
			}
		}
	}
	for(ll i=1;i<=n;i++)fa[i]=i;
	ll g=n;
	sort(s2+1,s2+1+tot,cmp);
	for(ll i=1;i<=tot;i++){
		if(g==1)break;
		ll u=s2[i].u,v=s2[i].v,w=s2[i].w;
		if(find(u)!=find(v)){
			fa[find(u)]=fa[find(v)];sum+=w;g--;
		}
	}
	ans=min(ans,sum);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	ll o=0;
	for(ll i=1;i<=k;i++){
		mi[i]=1;
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>xc[i][j];
			if(xc[i][j]<xc[i][mi[i]])mi[i]=j;
		}
		if(c[i]==0&&xc[i][mi[i]]==0)o+=1<<i-1;//特殊数据A 
	}
	solve0();
	for(ll i=1;i<(1<<k);i++){
		if((i&o)!=o)continue;//特殊数据A 
		solve(i);
	}
	cout<<ans<<'\n';
	return 0;
}
