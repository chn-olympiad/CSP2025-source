#include<cstdio>
#include<algorithm>
typedef long long LL;
const int N=1e4+10,M=1e6+10,K=15;
int n,m,k;
LL ans,res;
int c[N],a[K][N];
int f[N],g[K][N];
int p0[K];
bool vis[K];
struct Edge{
	int u,v,w;
}e[M<<1],E[N];
struct EDGE{
	int u,v,w,id;
}stk[M];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
template<typename T>inline T min(T a,T b){return a<b?a:b;}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
//inline void merge(int u,int v){
//	if(p[u]<p[v])u^=v^=u^=v;
//	for(int i=1;i<=k;++i)
//		a[i][u]=min(a[i][u],a[i][v]);
//	f[v]=u,p[u]+=p[v];
//}
inline void spA(){
	for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)if(j!=p0[i])
		e[++m]=(Edge){p0[i],j,a[i][j]};
	std::sort(e+1,e+m+1,[](const Edge &a,const Edge &b){return a.w<b.w;});
	for(int i=1,u,v,cnt=1;i<=m&&cnt<n;++i)if((u=find(e[i].u))!=(v=find(e[i].v)))
		f[v]=u,ans+=e[i].w,++cnt;
	printf("%lld\n",ans);
}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();bool spa=1;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i)
		e[i]=(Edge){read(),read(),read()};
	for(int i=1;i<=k;++i){
		c[i]=read(),spa&=(c[i]==0);
		for(int j=1;j<=n;++j)
			a[i][j]=read(),a[i][j]==0?p0[i]=j:0;
		spa&=(p0[i]>0);
	}
	if(k==0||spa)return spA(),0;
	std::sort(e+1,e+m+1,[](const Edge &a,const Edge &b){return a.w<b.w;});
	for(int i=1,u,v,cnt=1;i<=m&&cnt<n;++i)if((u=find(e[i].u))!=(v=find(e[i].v)))
		f[v]=u,ans+=e[i].w,E[cnt]=e[i],++cnt;//printf("%d\n",ans);
	for(int s=1;s<1<<k;++s){
		res=0;//puts("Use");
		for(int i=1;i<=n;++i)
			f[i]=i;
		for(int i=1,mn;i<=k;++i)if(s>>(i-1)&1){
			mn=1;
			for(int j=1;j<=n;++j)
				g[i][j]=a[i][j],g[i][mn]>g[i][j]?mn=j:0;
			res+=g[i][mn],g[i][mn]=0;
		}
		for(int i=0;i<k;++i)if(s>>i&1)
			res+=c[i+1];//,printf("%d ",i+1);
//			puts("");
		for(int i=1,u,v,val,vali;i<n;++i){
			u=find(E[i].u),v=find(E[i].v),val=E[i].w,vali=0;
			for(int j=1;j<=k;++j)if(s>>(j-1)&1)
				val>g[j][u]+g[j][v]?val=g[j][u]+g[j][v],vali=j:0;
			res+=val,g[vali][u]=g[vali][v]=0,f[v]=u;
			for(int j=1;j<=k;++j)if(s>>(j-1)&1)
				g[j][u]=min(g[j][u],g[j][v]);
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
//	for(int i=1,ti,fu,fv;i<=m;++i){
//		ti=i,top=0;
//		while(e[ti+1].w==e[ti].w)++ti;
//		for(int j=i;j<=ti;++j)if((fu=find(e[j].u))!=(fv=find(e[j].v))){
//			for(int l=1;l<=k;++l)
//				if(e[j].w>=a[l][fu]+a[l][fv]+(vis[l]?c[l]:0))
//					stk[++top]=(EDGE){fu,fv,a[l][fu]+a[l][fv]+(vis[l]?c[l]:0),vis[l]?0:l};
//				else
//					stk[++top]=(EDGE){fu,fv,e[j].w,0};
//		}
//		std::sort(stk+1,stk+top+1,[](const EDGE &a,const EDGE &b){return a.w==b.w?a.id>b.id:})
//		i=ti;
//	}
	return 0;
}
/*
16:56
60 pts

for 2^k
最小生成树的边去掉 

17:21
除了样例4全过了，但是是假的 

3 3 1
1 2 10000
2 3 10000
1 3 10000
10 1 2 100
113

3 3 1
1 2 1
2 3 10000
1 3 10000
10 3 2 100
113

17:42
不知道多少分 
*/
