#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf=1e15;
const int Maxn=2e6+6;
int n,m,k;
int a[12][Maxn];
int c[12];

struct edg{
	int u,v,w;
}E[Maxn],G[Maxn];
int f[Maxn],dep[Maxn],tot;

int qfind(int key){
	return key==f[key]?key:f[key]=qfind(f[key]);
}
inline void Merge(int u,int v){
	int qu=qfind(u),qv=qfind(v);
	if(qu==qv) return ;
	if(dep[qu]<dep[qv]) swap(qu,qv);
	f[qv]=qu, dep[qu]+=(dep[qu]==dep[qv]);
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[i]=(edg){u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	sort(E+1,E+m+1,[](edg x,edg y){
		return x.w<y.w;
	});
	
	for(int i=1;i<=n;i++) f[i]=i,dep[i]=0;
	for(int i=1;i<=m;i++){
		int u=qfind(E[i].u),v=qfind(E[i].v),w=E[i].w;
		if(u!=v){
			G[++tot]=E[i];
			Merge(u,v);
		}
	}
	
	ll ans=inf;
	for(int o=0;o<(1<<k);o++){
		int ntot=tot,vc=n; 
		for(int j=1;j<=tot;j++) E[j]=G[j];
		for(int j=1;j<=n*2;j++) f[j]=j,dep[j]=0;
		
		ll ret=0,now=0; int utot=0;
		for(int j=0;j<k;j++){
			if(o>>j&1){
				vc++; ret+=c[j+1];
				for(int p=1;p<=n;p++) E[++ntot]=(edg){p,vc,a[j+1][p]};
			}
		}
		sort(E+1,E+ntot+1,[](edg x,edg y){
			return x.w<y.w;
		});
		
		for(int i=1;i<=ntot;i++){
			int u=qfind(E[i].u),v=qfind(E[i].v),w=E[i].w;
			if(u!=v){
				utot++;
				ret+=w;
				if(utot==vc-1) break;	
				Merge(u,v);
			}
		}
		
		ans=min(ans,ret);
	}
	printf("%lld",ans);
	
	return 0;
}
/*
最小生成树。

O(2^kkn\alpha(n))
 
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
 
 
*/
