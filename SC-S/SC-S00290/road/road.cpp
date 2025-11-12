#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
const long long N=1e4+9,M=2e6+9;
struct EDGE{
	long long u,v,w,type;
	friend bool operator<(EDGE x,EDGE y){
		return x.w<y.w;
	}
}e[M];
struct node{
	long long v,w;
};
long long fa[N];
long long find(long long x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool query(long long x,long long y){return find(x)==find(y);}
void merge(long long x,long long y){fa[find(y)]=find(x);}
vector<node>edge[N];
long long fw[N],sz[N],f[N];
long long ans;
void dfs(long long u,long long F,long long W){
	f[u]=F,fw[u]=W;
	for(node v:edge[u]){
		if(v.v==F)continue;
		sz[u]++;
		dfs(v.v,u,v.w);
	}
}
long long c[15],a[N];
long long w[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		int x,cnt;
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
			if(a[j]==0)cnt=j;
		}
		if(!cnt||x!=0)continue;
		for(int j=1;j<=n;j++)
			if(j!=cnt)
				e[++m]={cnt,j,a[j],1};
		
	}
	sort(e+1,e+m+1);
	for(long long i=1;i<=m;i++){
		if(!query(e[i].u,e[i].v)){
			merge(e[i].u,e[i].v);
			edge[e[i].u].push_back({e[i].v,e[i].w});
			edge[e[i].v].push_back({e[i].u,e[i].w});
			ans+=e[i].w;
		}
	}
	printf("%lld\n",ans);
}