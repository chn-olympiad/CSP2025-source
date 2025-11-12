#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+50;
const int MAXM=2e6+10;
inline void Freopen(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int n,m,k;
struct node{
	int u,v,w;
}a[MAXM],b[MAXM];
int tot;
int c[15];
int v[15][MAXN];
int fa[MAXN];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline long long kruskal(int x){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(a+1,a+tot+1,[](const node &x,const node &y){return x.w<y.w;});
	int cnt=0; long long ans=0;
	for(int i=1;i<=tot;i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v){
			fa[u]=v; cnt++;
			ans+=a[i].w;
		}
		if(cnt==n+x-1) return ans;
	}
	return 1e18;
}
signed main(){
	Freopen();
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		a[i]={u,v,w}; b[i]=a[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>v[i][j];
	}
	long long ans=1e18;
	for(int S=0;S<(1<<k);S++){
		for(int i=1;i<=m;i++) a[i]=b[i];
		long long sum=0; int x=0; tot=m;
		for(int i=0;i<k;i++) if((S>>i)&1){
			sum+=c[i+1]; x++;
			for(int j=1;j<=n;j++) a[++tot]={n+i+1,j,v[i+1][j]};
		}
//		if(S==1) cout<<kruskal()+sum<<'\n';
		ans=min(ans,kruskal(x)+sum);
	}
	cout<<ans<<'\n';
	return 0;
}

