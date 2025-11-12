#include<bits/stdc++.h>
using namespace std;
#define filename "road"
const int N=1e4+2,M=1e6+2;
int n,m,k,c[12][N];
struct edge{
	int u,v,w,typ;
	bool vis;
}e[M<<1];
long long ans;

namespace kkrl{
	int fa[N];
	
	int f(int X){
		return fa[X]==X?X:fa[X]=f(fa[X]);
	}
	
	void krl(){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(e+1,e+m+1,[](edge A,edge B){return A.w<B.w;});
		int cnt=0;
		for(int i=1;i<=m&&cnt<n-1;i++){
			int a=f(e[i].u),b=f(e[i].v);
			if(a!=b){
				fa[b]=a;
				cnt++;
				ans+=e[i].w;
			}
		}
	}
}

namespace kkkrl{
	int fa[N];
	
	int f(int X){
		return fa[X]==X?X:fa[X]=f(fa[X]);
	}
	
	void krl(){
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i][0]);
			for(int j=1;j<=n;j++) scanf("%d",&c[i][j]);
			for(int u=1;u<=n;u++) for(int v=1;v<=n;v++) if(u!=v)
				e[++m]=(edge){u,v,c[i][u]+c[i][0]+c[i][v],i,false};
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(e+1,e+m+1,[](edge A,edge B){return A.w<B.w;});
		int cnt=0;
		for(int i=1;i<=m&&cnt<n-1;i++) if(!e[i].vis){
			int a=f(e[i].u),b=f(e[i].v);
			if(a!=b){
				fa[b]=a;
				cnt++;
				ans+=e[i].w;
				e[i].vis=true;
				if(e[i].typ){
					for(int j=i+1;j<=m;j++) if(e[j].typ==e[i].typ)
						e[j].w-=c[e[j].typ][0];
					sort(e+1,e+m+1,[](edge A,edge B){return A.w<B.w;});
					i=1;
				}
			}
		}
	}
}

int main(){
#ifdef filename
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].typ=0,e[i].vis=false;
	}
	if(k==0) kkrl::krl();
	else kkkrl::krl();
	cout<<ans;
	return 0;
}