#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return x;
}
const int N=1e4+13,M=2e6+3;
int n,m,mm,k,c[13],a[13][N];
struct edge{int u,v,w;friend bool operator <(edge x,edge y){return x.w<y.w;}}e[M],E[M];
bool abl[N];
ll ans=LLONG_MAX;
int fa[N];
inline int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) E[i].u=read(),E[i].v=read(),E[i].w=read();
	sort(E+1,E+1+m);
	iota(fa+1,fa+1+n,1);
	for(int i=1;i<=m;i++){
		int u=Find(E[i].u),v=Find(E[i].v);
		if(u==v) continue;
		fa[u]=v,e[++mm]=E[i];
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read(),e[++mm]=edge{i+n,j,a[i][j]}; 
	}
	m=mm;
	sort(e+1,e+1+m);
	for(int S=0;S<(1<<k);S++){
		ll sum=0;
		for(int i=1;i<=k;i++){
			if((S>>i-1)&1) abl[n+i]=1,sum+=c[i];
			else abl[n+i]=0;
		}
		iota(fa+1,fa+1+n+k,1);
		int cnt=0,pc=__builtin_popcount(S);
		for(int i=1;i<=m && cnt<n+pc-1;i++){
			if(e[i].u>n && !abl[e[i].u]) continue;
			int u=Find(e[i].u),v=Find(e[i].v),w=e[i].w;
			if(u==v) continue;
			fa[u]=v,cnt++,sum+=w;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
//15:16 pass all,checking 80pts 51697684656

