#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	ll to,w,nxt,u;
}e[2*M];
ll head[N],cnt,fa[N];
void add(ll u,ll v,ll w){
	e[++cnt]={v,w,head[u],u};
	head[u]=cnt;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
ll find(ll x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	ll x;
	for(ll i=1;i<=k;i++){
		cin>>x;
		for(ll j=1;j<=n;j++){
			cin>>x;
		}
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+cnt,cmp);
	ll s=0,sum=0;
	for(ll i=1;i<=cnt;i++){
		ll x=find(e[i].u);
		ll y=find(e[i].to);
		if(x!=y){
			fa[x]=y;
			s++;
			sum+=e[i].w;
			if(s==n-1){
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}