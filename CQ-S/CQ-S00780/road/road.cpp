#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define eb emplace_back
char buf[1<<21],*p1=buf,*p2=buf;
inline char gc(){return p1==p2?(p2=(p1=buf)+fread(buf,1,1<<21,stdin),(p1==p2?EOF:*p1++)):(*p1++);}
inline int read(){
	int res=0;
	char c=gc();
	while(c<'0'||c>'9') c=gc();
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=gc();
	return res;
}
const int N=1e4+10,M=1e6+10,inf=1e9+10;
int n,m,k,fa[N],ne[12][N],p[12],mn,s;
pii a[12][N];
ll ans,f[1<<10],W[12];
bool vis[12];
struct edge{
	int u,v,w;
}len[M];
inline int gf(int F[],int x){return F[x]==x?x:F[x]=gf(F,F[x]);}
inline void getne(){
	W[mn=0]=inf;
	int S=s;
	while(S){
		int i=__lg(S)+1;S^=(1<<i-1);
		p[i]=n+1;
		int x=1;
		while(x<=n){
			int y=gf(ne[i],x)+1;
//			cerr<<x<<" -> "<<y<<"\n";
			if(y>n||gf(fa,a[i][x].second)!=gf(fa,a[i][y].second)){p[i]=y;break;}
			ne[i][y-1]=y,x=y;
		}
		W[i]=(p[i]<=n?(!vis[i])*a[i][1].first+a[i][p[i]].first:inf);
		if(W[i]<W[mn]) mn=i;
//		cerr<<i<<" "<<p[i]<<" getne\n";
	}
//	cerr<<mn<<" ov\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i) len[i].u=read(),len[i].v=read(),len[i].w=read();
	sort(len+1,len+1+m,[](edge x,edge y){return x.w<y.w;});
	for(int i=1;i<=n;++i) fa[i]=i;
	int tot=0;
	for(int i=1;i<=m;++i){
		int u=gf(fa,len[i].u),v=gf(fa,len[i].v);
		if(u!=v) fa[u]=v,len[++tot]=len[i],ans+=len[i].w;
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j) a[i][j].first=read(),a[i][j].second=j;
		sort(a[i]+1,a[i]+1+n);
	}
	for(s=1;s<1<<k;++s){
		int u=__lg(s)+1,t=(s^(1<<u-1));
		f[s]=f[t]+a[u][0].first;
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=1;i<=k;++i){vis[i]=0;for(int j=1;j<=n+1;++j) ne[i][j]=j;}
		getne();
		ll res=f[s];
		for(int i=1;i<n;++i){
			while(mn&&W[mn]<len[i].w){
				vis[mn]=1;
				int x=gf(fa,a[mn][1].second),y=gf(fa,a[mn][p[mn]].second);
				if(x!=y) fa[x]=y,res+=W[mn];
				getne();
			}
			int x=gf(fa,len[i].u),y=gf(fa,len[i].v);
			if(x!=y) fa[x]=y,res+=len[i].w,getne();
		}
		ans=min(ans,res);
//		cerr<<s<<" "<<res<<"----\n";
	}
	printf("%lld",ans);
	return 0;
}
