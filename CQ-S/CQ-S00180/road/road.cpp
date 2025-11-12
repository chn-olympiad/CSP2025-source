#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+15,NN=1e6+15;
int n,m,k,fa[N],c[11],xixi;
bool vis[11];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct tlhll{
	int u,v,w;
	bool operator<(const tlhll &x)const{
		return w<x.w;
	}
}a[NN];
int cnt;
struct tlh{
	int u,v,w,op;
	bool operator<(const tlh &x)const{
		return w<x.w;
	}
}d[NN];
ll ans,res;
void krus(){
	int tot=0;
	for(int i=1;i<=m;i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u==v) continue;
		fa[u]=v;
		d[++cnt]={a[i].u,a[i].v,a[i].w,0};
		ans+=a[i].w;
		++tot;
		if(tot==n-1) return;
	}
}
void krudeus(){
	int tot=0;
	for(int i=1;i<=cnt;i++){
		if(vis[d[i].op]){
			int u=find(d[i].u),v=find(d[i].v);
			if(u==v) continue;
			res+=d[i].w;
			if(res>=ans) return;
			fa[u]=v;
			++tot;
			if(tot==n+xixi-1) return;
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	krus();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;
			d[++cnt]={n+i,j,x,i};
		}
	}
	sort(d+1,d+cnt+1);
	vis[0]=1;
	for(int g=1;g<(1<<k);g++){
		res=xixi=0;
		for(int i=1;i<=k;i++) vis[i]=bool((1<<(i-1))&g);
		for(int i=1;i<=k;i++)
			if(vis[i]) res+=c[i],++xixi;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		krudeus();
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
