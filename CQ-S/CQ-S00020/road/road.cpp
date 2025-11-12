#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=1e6+5,N=1e4+5;
int n,m,k,cnt1;

int lsh[Maxn],cnt2;

struct edge{
	int u,v,w;
}e[Maxn],G[Maxn],E[Maxn],a[12][N],tp[Maxn];
int c[Maxn];

int f[Maxn],si[Maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int u,int v){
	if(si[u]<si[v])swap(u,v);
	si[u]+=si[v];f[v]=u;
}


inline ll sol(int s){
	for(int i=1;i<=n+k;i++)f[i]=i,si[i]=1;
	ll res=0;
	for(int i=1;i<=cnt1;i++)E[i]=G[i];
	
	int tot=cnt1;
	for(int i=1;i<=k;i++)if((s>>i-1)&1){
		res+=c[i];int p=1,now=0;
		for(int j=1;j<=n;j++){
			while(p<=tot&&E[p].w<=a[i][j].w)tp[++now]=E[p],++p;
			tp[++now]=a[i][j];
		}
		tot=now;for(int j=1;j<=tot;j++)E[j]=tp[j];
	}
	
	int all=1,chk=n+__builtin_popcount(s);
	
	for(int i=1;i<=tot;i++){
		int u=find(E[i].u),v=find(E[i].v),w=E[i].w;
		if(u==v)continue;
		merge(u,v);
		all++;res+=lsh[w];
		if(all==chk)break;
	}return res;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)e[i]={read(),read(),read()};
	
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int w=read();lsh[++cnt2]=w;
			a[i][j]={n+i,j,w};
		}
		sort(a[i]+1,a[i]+1+n,[&](const edge x,edge y){return x.w<y.w;});
	}
	
	sort(e+1,e+1+m,[&](const edge a,edge b){return a.w<b.w;});
	
	ll ans=0;
	
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		G[++cnt1]=e[i];
		lsh[++cnt2]=w;
		ans+=w;f[find(u)]=find(v);
	}
	
	sort(lsh+1,lsh+1+cnt2);
	cnt2=unique(lsh+1,lsh+1+cnt2)-lsh-1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)a[i][j].w=lower_bound(lsh+1,lsh+1+cnt2,a[i][j].w)-lsh;
	for(int i=1;i<=cnt1;i++)G[i].w=lower_bound(lsh+1,lsh+1+cnt2,G[i].w)-lsh;
	
	for(int s=1;s<(1<<k);s++)ans=min(ans,sol(s));
	printf("%lld\n",ans);
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

