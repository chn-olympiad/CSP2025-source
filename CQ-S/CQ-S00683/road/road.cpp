#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10,M=1e4+10;
int n,m,k,fa[M],c[12][M],vis[12];
struct node{
	int u,v,w,id;
	bool operator<(const node&b)const{
		return w<b.w;
	}
}e[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;ans+=e[i].w;
	}
	cout<<ans;
}
void solve2(){
	int ans=0,cnt=m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>c[i][j];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++) e[++cnt]={j,k,c[i][0]+c[i][j]+c[i][k],i};
		}
	}
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;ans+=e[i].w;
		if(vis[e[i].id]) ans-=c[e[i].id][0];
		vis[e[i].id]=1; 
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	if(!k) solve1();
	else solve2();
	return 0;
}
