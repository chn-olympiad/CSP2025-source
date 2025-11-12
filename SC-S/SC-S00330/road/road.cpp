#include<bits/stdc++.h>//2^k+prim 
#define int long long
#define M 1000010
#define N 10030
using namespace std;
int n,m,k,c[15],ans=1e15;
int fa[N];
struct edge{
	int u,v,w;
}e[M<<1],ex[12][N],ee[N<<4];
int gf(int x){
	if(fa[x]==x)return x;
	return fa[x]=gf(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for(int j=1,cv;j<=n;++j){
			scanf("%lld",&cv);
			ex[i][j]=(edge){n+i,j,cv};
		}
	}
	int cnt;
	int asdf=(1<<k)-1;
	for(int i=0;i<=asdf;++i){
		cnt=0;
		int tot=0,adeg=0,js=0;
		for(int j=1;j<=n+k;++j)fa[j]=j;
		for(int j=1;j<=k;++j){
			if(i&(1<<(j-1))){
				tot+=c[j];
				++js;
				for(int op=1;op<=n;++op){
					ee[++cnt]=ex[j][op];
				}
			}
		}
		if(cnt)sort(ee+1,ee+cnt+1,cmp);
		for(int l1=1,l2=1;l1<=m||l2<=cnt;){
			if(l2>cnt){
				int fx=gf(e[l1].u),fy=gf(e[l1].v);
				if(fx!=fy){
					++adeg;
					tot+=e[l1].w;
					fa[fx]=fy;
				}
				++l1;
			}
			else if(l1>m){
				int fx=gf(ee[l2].u),fy=gf(ee[l2].v);
				if(fx!=fy){
					++adeg;
					tot+=ee[l2].w;
					fa[fx]=fy;
				}
				++l2;
			}
			else if(e[l1].w<=ee[l2].w){
				int fx=gf(e[l1].u),fy=gf(e[l1].v);
				if(fx!=fy){
					++adeg;
					tot+=e[l1].w;
					fa[fx]=fy;
				}
				++l1;
			}
			else{
				int fx=gf(ee[l2].u),fy=gf(ee[l2].v);
				if(fx!=fy){
					++adeg;
					tot+=ee[l2].w;
					fa[fx]=fy;
				}
				++l2;
			}
			if(adeg>=n+js-1)break;
		}
		ans=min(ans,tot);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/