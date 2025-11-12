#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+100,M=2e6+10;
int n,m,k,fa[N],siz[N],a[15][N],c[15];
int cnt=0,ans=0,tcnt=0;
int vis[15];
struct edge{
	int u,v,w,idx;
}e[M],cur[M];

bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]=(x==fa[x])?x:find(fa[x]);
}
void merge(int x,int y){
	int i=find(x),j=find(y);
	(siz[i]>siz[j])?fa[j]=i:fa[i]=j;
}
void Kruskal1(){
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=cnt;i++){
		if(e[i].idx!=0) continue;
		if(find(e[i].u)==find(e[i].v)) continue;
		merge(e[i].u,e[i].v),ans+=e[i].w;
		cur[++tcnt]={e[i].u,e[i].v,e[i].w,0};
	}
}
void Kruskal2(int v){
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	int sum=0;
	for(int i=1;i<=tcnt;i++){
		if(!vis[cur[i].idx]) continue;
		if(find(cur[i].u)==find(cur[i].v)) continue;
		merge(cur[i].u,cur[i].v),sum+=cur[i].w;
	}
	ans=min(ans,sum+v);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k; cnt=m;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w,e[i].idx=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j],cur[++tcnt]={i+n,j,a[i][j],i};
	}
	sort(e+1,e+cnt+1,cmp);
	Kruskal1(); sort(cur+1,cur+tcnt+1,cmp);
	for(int i=1;i<(1<<k);i++){
		memset(vis,0,sizeof(vis));
		vis[0]=1; int v=0;
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1))) v+=c[j],vis[j]=1;
		Kruskal2(v);
	}
	cout<<ans<<endl;
	return 0;
}