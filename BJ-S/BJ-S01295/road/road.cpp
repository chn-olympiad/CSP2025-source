#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	int u,v;
	ll w;
	friend bool operator < (Edge x,Edge y){
		return x.w<y.w;
	}
}e[1000005],t[20005];
int root[20005];
bool vis[15];
ll c[15];
int findroot(int x){
	if(x==root[x]) return x;
	else return root[x]=findroot(root[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,tmp,idx=0;
	ll ans=0,res=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) root[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		int fu=findroot(e[i].u),fv=findroot(e[i].v);
		if(fu==fv) continue;
		ans+=e[i].w;
		e[++idx]=e[i];
		root[fu]=root[fv];
		if(idx==n-1) break;
	}
	cout<<ans;
	return 0;
}