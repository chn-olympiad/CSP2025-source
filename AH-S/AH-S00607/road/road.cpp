#include<bits/stdc++.h>
using namespace std;
const int Maxm=1000005,Maxn=11005,Maxs=1105;
int n,m,k,fa[Maxn],tot,c[15],sz[Maxn],cnt,len[Maxs];
typedef long long ll;
ll ans,res;
struct edge{
	int u,v,w;
	bool operator<(const edge &u)const{return w<u.w;}
}e[Maxm],ne[Maxs][Maxn],tmp[Maxn<<1],G[15][Maxn];
int Find(int a){return fa[a]==a?a:(fa[a]=Find(fa[a]));}
bool Merge(int x,int y){
	if ((x=Find(x))==(y=Find(y))) return 0;
	if (sz[x]>sz[y]) swap(x,y);
	fa[x]=y;sz[y]+=sz[x];--cnt;return 1;
}
int Merge2(edge e1[],edge e2[],int len1,int len2){
	for(int i=1,p=1,q=1;i<=len1+len2;++i){
		if (q>len2||(p<=len1&&e1[p]<e2[q])) tmp[i]=e1[p++];
		else tmp[i]=e2[q++];
	}
	return len1+len2;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m);
	for(int i=1;i<=k;++i){
		scanf("%d",c+i);
		for(int j=1;j<=n;++j){G[i][j].u=i+n;G[i][j].v=j;scanf("%d",&G[i][j].w);}
		sort(G[i]+1,G[i]+1+n);
	}
	cnt=n;for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m&&cnt!=1;++i) if (Merge(e[i].u,e[i].v)) ne[0][++len[0]]=e[i],ans+=e[i].w;
	for(int S=1;S<(1<<k);++S){
		int low=0;
		for(int i=0;i<k;++i) if (S&(1<<i)){low=i;break;}
		int l=Merge2(ne[S^(1<<low)],G[low+1],len[S^(1<<low)],n);
		cnt=n+k;for(int i=1;i<=n+k;++i) fa[i]=i,sz[i]=1;
		res=0;for(int i=0;i<k;++i) if (S&(1<<i)) res+=c[i+1];
		for(int i=1;i<=l&&cnt!=1;++i) if (Merge(tmp[i].u,tmp[i].v)){res+=tmp[i].w;ne[S][++len[S]]=tmp[i];}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
