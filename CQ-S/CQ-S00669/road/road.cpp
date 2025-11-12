#include <bits/stdc++.h>
using namespace std;
namespace lyj{
	const int N=1e4+5,M=1e6+5,K=1e1+5;
	int n,m,k,cnt,a[K][N],f[N],ans,c[K];
	struct edge{
		int from,to,nxt,val;
	}g[M*8];
	void add(int u,int v,int w){
		g[++cnt].from=u;g[cnt].to=v;g[cnt].val=w;
	}
	int get_f(int x){
		if(f[x]==x)return x;
		return f[x]=get_f(f[x]);
	}
	bool cmp(edge x,edge y){
		return x.val<y.val;
	}
	void kru(){
		int cnt_=0;
		for(int i=1;i<=cnt;i++){
			int u=g[i].from,v=g[i].to,w=g[i].val;
			int fu=get_f(u),fv=get_f(v);
			if(fu==fv)continue;
			else{
				f[fu]=fv;ans+=w;cnt_++;
				if(cnt_==n-1)return ;
			}
		}
	}
	int main(){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){f[i]=i;}
		for(int i=1;i<=m;i++){int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);}
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					add(j,l,a[i][j]+a[i][l]+c[i]);
				}
			}
		}sort(g+1,g+cnt+1,cmp);kru();
		printf("%d",ans);
		return 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	lyj::main();return 0;
}
