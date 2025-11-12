#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,res,cnt;
struct N{
	ll u,v,w;
	friend bool operator<(N a,N b){return a.w<b.w;}
}e[1000010];
ll c[110],fa[10002];
ll a[12][10002];
inline ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(e+1,e+m+1);
	for(ll i=1;i<=m;i++){
		ll fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			cnt++;
			res+=e[i].w;
			fa[fu]=fv;
		}
		if(cnt>=n-1)break;
	}
	if(k<=0){
		cout<<res<<"\n";
		return 0;
	}
	return 0;
} 
