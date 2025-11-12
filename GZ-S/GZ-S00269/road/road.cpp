//GZ-S00269 ×ñÒåÌìÁ¢ ÑîÈó¿­ 
#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e4+5,maxm=1e6+5;
struct edge{
	int u,v,w,ne;
}e[maxm<<2];
int n,m,k;

int head[maxn<<1],len;
void insert(int u,int v,int w){
	e[++len]={u,v,w,head[u]},head[u]=len;
}
bool cmp(edge a,edge b){
	if(a.w==b.w)return a.u<b.u;
	return a.w<b.w;
}

int fa[maxn<<1];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}

int a[15],c[15][maxn];
void rink(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		insert(u,v,w),insert(v,u,w);
	}
	
	for(int i=1;i<=k;++i){
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;++j){
			scanf("%lld",&c[i][j]);
			insert(n+i,j,a[i]+c[i][j]);
			insert(j,n+i,a[i]+c[i][j]);
		}
	}
	
}


int cnt,ans;
bool vis[maxn],vv[15];
void kruskal(){
	sort(e+1,e+len+1,cmp);
	for(int i=1;i<=len;++i){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
		    ans+=e[i].w;
			if(u>n&&vv[u])ans-=a[u-n];
			if(v>n&&vv[v])ans-=a[v-n];
			fa[fv]=fu;
			if(u<=n&&!vis[u])
				++cnt,vis[u]=1;
			if(v<=n&&!vis[v])
				++cnt,vis[v]=1;
			if(u>n)vv[u]=1;
			if(v>n)vv[v]=1;
		}
		if(cnt==n)return;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rink();
	kruskal();
	printf("%lld\n",ans);
	return 0;
}
