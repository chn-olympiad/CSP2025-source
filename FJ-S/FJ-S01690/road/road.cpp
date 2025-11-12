#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define gc()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define FIN(x) freopen(x".in","r",stdin);
#define FOUT(x) freopen(x".out","w",stdout);
#define ll int
#define il inline
#define re register int
#define rl register ll
using namespace std;
const int MN=1e6+50,MM=1e3+5;
ll n,m,k,fa[MN>>1],tot,c[MN],a[11][MN>>1],mp[MM][MM],u[MN],v[MN],w[MN],tmp[MM][MM];
long long ans;
struct edge{ll u,v,w;}e[MN];
char buf[1<<23],*p1=buf,*p2=buf;
il int read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(long long x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
il bool cmp(edge a, edge b){return a.w<b.w;}
il ll find(rl x){return x==fa[x]?x:fa[x]=find(fa[x]);}
il long long kruskal(){
	long long cnt=0,ans=0;
	for(re i=1; i<=n+k; ++i) fa[i]=i;
	sort(e+1,e+1+tot,cmp);
	for(re i=1; i<=tot; ++i){
		ll u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		++cnt;ans+=e[i].w;fa[u]=v;
		if(cnt==n-1) return ans;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	n=read();m=read();k=read();
	for(re i=1; i<=m; ++i){u[i]=read();v[i]=read();w[i]=read();if(u[i]>v[i])swap(u[i],v[i]);e[++tot]={u[i],v[i],w[i]};}
	if(k==0){write(ans=kruskal());putchar('\n');return 0;}
	ans=kruskal();
	for(re i=1; i<=k; ++i){
		c[i]=read();
		for(re j=1; j<=n; ++j) a[i][j]=read();
	}
	for(re S=0; S<(1<<k); S+=2){
		for(re i=1; i<=n; ++i) for(re j=i+1; j<=n; ++j) mp[i][j]=2e9;
		for(re i=1; i<=m; ++i) mp[u[i]][v[i]]=w[i]; 
		long long cnt=0;tot=0;
		for(re i=2; i<=k; ++i) if((S>>(i-1))&1) cnt+=c[i];
		if(cnt>ans) continue; 
		for(re i=2; i<=k; ++i) if((S>>(i-1))&1) for(re x=1; x<=n; ++x) for(re y=x+1; y<=n; ++y) mp[x][y]=min(mp[x][y],a[i][x]+a[i][y]);
		for(re i=1; i<=n; ++i) for(re j=i+1; j<=n; ++j) e[++tot]={i,j,mp[i][j]};
		ans=min(ans,cnt+kruskal());
	}
	for(re i=1; i<=n; ++i) for(re j=i+1; j<=n; ++j) tmp[i][j]=2e9;
	for(re i=1; i<=m; ++i) tmp[u[i]][v[i]]=w[i];
	for(re i=1; i<=n; ++i) for(re j=i+1; j<=n; ++j) tmp[i][j]=min(tmp[i][j],a[1][i]+a[1][j]); 
	for(re S=1; S<(1<<k); S+=2){
		for(re i=1; i<=n; ++i) for(re j=i+1; j<=n; ++j) mp[i][j]=tmp[i][j];
		long long cnt=c[1];tot=0;
		for(re i=2; i<=k; ++i) if((S>>(i-1))&1) cnt+=c[i];
		if(cnt>ans) continue; 
		for(re i=2; i<=k; ++i) if((S>>(i-1))&1) for(re x=1; x<=n; ++x) for(re y=x+1; y<=n; ++y) mp[x][y]=min(mp[x][y],a[i][x]+a[i][y]);
		for(re i=1; i<=n; ++i) for(re j=i+1; j<=n; ++j) e[++tot]={i,j,mp[i][j]};
		ans=min(ans,cnt+kruskal());
	}
	write(ans);putchar('\n');
	return 0;
}//251101 CSP2025 RP++
