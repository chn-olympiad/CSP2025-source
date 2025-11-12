#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
constexpr int N=1e4+10,M=1e6+10;
int n,m,k,fa[N+20],cnt,c[15],a[15][N],tot,cntk;
ll ans,now;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct edge{
	int u,v,w;
	bool operator<(const edge &x)const{return w<x.w;}
}e[M],g[N],h[N*15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;
		ans+=e[i].w;
		g[++cnt]=e[i];
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int s=1;s<(1<<k);s++){
		now=0,tot=n-1,cntk=n;
		for(int i=1;i<n;i++) h[i]=g[i];
		for(int i=0;i<k;i++){
			if(s>>i&1){
				now+=c[i+1];
				++cntk;
				for(int j=1;j<=n;j++)
					h[++tot]={j,cntk,a[i+1][j]};
			}
		}
		sort(h+1,h+1+tot);
		cnt=0;
		for(int i=1;i<=cntk;i++) fa[i]=i;
		for(int i=1;i<=tot;i++){
			int x=find(h[i].u),y=find(h[i].v);
			if(x==y) continue;
			fa[x]=y;
			now+=h[i].w;
			++cnt;
			if(cnt==cntk-1) break;
		}
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
	return 0;
}
