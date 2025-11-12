#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rd(){int x=0;char ch=getchar();while(!isdigit(ch)) ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x;}
const int N=1e4+50,M=1e6+10;
int n,m,k,fa[N],c[10],w[10][N];
ll ans;
struct edge{int u,v,w;}e[M],g[N];

bool cmp(edge x,edge y){return x.w<y.w;}

int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++) e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	for(int i=0;i<k;i++){
		c[i]=rd();
		for(int j=1;j<=n;j++) w[i][j]=rd();	
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m&&cnt!=n-1;i++){
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		cnt++,ans+=e[i].w;
		g[cnt]=e[i];
	}
	for(int S=1;S<(1<<k);S++){
		for(int i=1;i<n;i++) e[i]=g[i];
		m=n-1,cnt=0;
		ll res=0;
		int x=n;
		for(int i=0;i<k;i++) if((S>>i)&1){
			x++,res+=c[i];
			for(int j=1;j<=n;j++) e[++m]={j,x,w[i][j]};
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=x;i++) fa[i]=i;
		for(int i=1;i<=m&&cnt!=x-1;i++){
			int u=Find(e[i].u),v=Find(e[i].v);
			if(u==v) continue;
			fa[u]=v;
			cnt++,res+=e[i].w;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
