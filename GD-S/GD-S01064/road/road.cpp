#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=1e7+10,K=20;
struct edge{
	int u,v,w,id;
}edges[M];
bool cmp(edge a,edge b){
	if(a.w==b.w)return a.id<b.id;
	return a.w<b.w;
}
int n,m,k,tot;
bool A=1;
int kk[K][N];
int f[N];
int find(int k){
	if(f[k]!=k)f[k]=find(f[k]);
	return f[k];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		edges[tot++]={u,v,w,tot};
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%lld",&kk[i][j]);
		bool flag=1;
		for(int j=1;j<=n;j++)flag&=kk[i][j];
		A&=!(flag||kk[i][0]);
	}
	if(A){
		for(int i=0;i<N;i++)f[i]=i;
		for(int i=1;i<=k;i++){
			int p;
			for(int j=1;j<=n;j++)if(!kk[i][j])p=j;
			for(int j=1;j<=n;j++){
				if(p==j)continue;
				edges[tot++]={p,j,kk[i][j],tot};
			}
		}
		sort(edges,edges+tot,cmp);
		int ans=0;
		for(int i=0;i<tot;i++){
			edge a=edges[i];
			if(find(a.u)!=find(a.v))
				f[find(a.u)]=find(a.v),
				ans+=a.w;
		}
		printf("%lld",ans);
	}else{
		int minn=LLONG_MAX;
		for(int i=0;i<(1<<k);i++){
			printf("@%lld ",i);
			for(int j=0;j<N;j++)f[j]=j;
			tot=m;
			int j=i;
			int w=0;
			while(j){
				w++;
				if(j&1){
					int u=n+2*w,v=u+1;
					for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
						edges[tot++]={u,x,kk[w][x],tot};
						edges[tot++]={v,y,kk[w][y],tot};
					}
					edges[tot++]={u,v,kk[w][0],tot};
				}
				j>>=1;
			}
			printf("%%1");
			int ans=0;
			sort(edges,edges+tot,cmp);
//			printf("!");
			for(int i=0;i<tot;i++){
				edge a=edges[i];
				if(find(a.u)!=find(a.v))
					f[find(a.u)]=find(a.v),
					ans+=a.w;
//				printf("#lld ",ans);
			}
			printf("%%2");
			minn=min(minn,ans);
//			printf("%lld ",ans);
		}
		printf("%lld",minn);
	}
	return 0;
}
