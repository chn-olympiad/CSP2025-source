#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{
	ll u,v,w;
}side[M];
ll n,m,k,a[15][N],f[N];
vector<pair<ll,ll>>g[N];
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]); 
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		side[i]={u,v,w};
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	if(k==0){
		for(int i=1;i<=n;i++) f[i]=i;
		sort(side+1,side+1+m,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++){
			int u=side[i].u,v=side[i].v,w=side[i].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				ans+=w;
				f[fu]=fv;
			}
		}
		cout<<ans;
		return 0;
	}
	bool f=0;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++){cin>>a[i][j];if(a[i][j]!=0) f=1;}
	
	return 0;
}  
