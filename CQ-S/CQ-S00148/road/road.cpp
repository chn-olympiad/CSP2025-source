#include<bits/stdc++.h>
#define MAXN 15000
#define MAXM 1000100
using namespace std;
namespace Aleister{
	int n,m,k,c[20],cnt;
	struct ed{
		int x,y,w;
	}e[MAXM],ee[MAXN],town[12][MAXN],ls[MAXN*15];
	bool cmp(ed x,ed y){if(x.w!=y.w) return x.w<y.w; if(x.x!=y.x) return x.x<y.x; return x.y<y.y;}
	struct dsu{
		int fa[MAXN],sz[MAXN];
		void init(){
			for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
		}
		int getfa(int x){
			if(fa[x]==x) return x;
			else return fa[x]=getfa(fa[x]);
		}
		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if(x==y) return;
			if(sz[x]<sz[y]) swap(x,y);
			fa[y]=x,sz[x]+=sz[y];
		}
	}d;
	void kr(){
		d.init();
		for(int i=1;i<=m;i++){
			int x=e[i].x,y=e[i].y;
			x=d.getfa(x),y=d.getfa(y);
			if(x==y) continue;
			d.merge(x,y),ee[++cnt]=(ed){e[i].x,e[i].y,e[i].w};
			if(cnt==n-1) break;
		}
	}
	long long ans=1e18;
	bool used[15];
	void check(){
		int tot=0,node=n;
		long long ret=0;
		for(int i=1;i<=n-1;i++) ls[++tot]=ee[i];
		for(int i=1;i<=k;i++){
			if(!used[i]) continue;
			node++,ret+=c[i];
			for(int j=1;j<=n;j++) ls[++tot]=town[i][j];
		}
		sort(ls+1,ls+1+tot,cmp);
		d.init();
		for(int i=1;i<=tot;i++){
			int x=ls[i].x,y=ls[i].y;
			x=d.getfa(x),y=d.getfa(y);
			if(x==y) continue;
			d.merge(x,y),node--,ret+=ls[i].w;
			if(node==1) break;
		}
		ans=min(ans,ret);
//		for(int i=1;i<=k;i++) cerr<<used[i]<<' ';
//		cerr<<":";
//		cerr<<ret<<'\n';
	}
	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
//		double START=clock();
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++) town[i][j].x=n+i,town[i][j].y=j,scanf("%d",&town[i][j].w);
			sort(town[i]+1,town[i]+1+n,cmp);
		}
		kr();
		for(int i=0;i<(1<<k);i++){
			for(int j=1;j<=k;j++) used[j]=i&(1<<(j-1));
			check();
		}
		printf("%lld\n",ans);
//		double END=clock();
//		cerr<<END-START<<'\n';
		return 0;
	}
}
int main(){
	return Aleister::main();
} 
//ºÃÏ²»¶¶°¶°°¡ 
