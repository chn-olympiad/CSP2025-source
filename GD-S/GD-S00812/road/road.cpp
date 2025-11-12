#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
const long long inf=2e18;
#define mkp make_pair 
int T=1;
int n,m,k;
long long res,ans,sum;
struct Edge{
	int u,v,w;
}E[N],e[N];
inline bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int pre[N],mini[15][N];
int vis[N];
int tmp,cnt;
int c[15][N];
inline void init(int n){
	for(int i=1;i<=n;i++){
		pre[i]=i;
		for(int j=1;j<=10;j++)
			mini[j][i]=c[j][i];
	}
}
inline int find(int x){
	return x==pre[x]?x:pre[x]=find(pre[x]);
}
inline void merge(int x,int y){
	if(find(x)==find(y))return ;
	pre[pre[x]]=pre[y];
	for(int i=1;i<=k;i++)mini[i][pre[y]]=min(mini[i][pre[y]],mini[i][pre[x]]);
}
inline void mst(int S){
	int cnt=n-1;
	init(n);
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)!=find(v)){
			for(int o=1;o<=k;o++)
				if(S&(1<<(o-1))){
					w=min(w,mini[o][pre[u]]+mini[o][pre[v]]);
				}
			merge(u,v);
			sum+=w;
			--cnt;
			if(!cnt)return;
		}
	}
}
void solve(){
	ans=inf; 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	}
	for(int i=1;i<=k;++i){
		int f=0;
		scanf("%d",&c[i][0]);
		if(c[i][0]>1)f=1;
		for(int j=1;j<=n;++j){
			scanf("%d",&c[i][j]);
			if(c[i][j]>1)f=1;
		}
		if(!f)ans=0; 
	}
	mst(0);
	ans=min(ans,sum);
//	printf("%lld\n",res);
//	int U=1<<k;
//	for(int S=1;S<U;++S){
//		sum=0;
//		for(int j=1;j<=k;++j)
//			if(S&(1<<(j-1)))sum+=c[j][0];
//		mst(S);
//		ans=min(ans,sum);
//	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	while(T--){solve();}
	return 0;
} 
