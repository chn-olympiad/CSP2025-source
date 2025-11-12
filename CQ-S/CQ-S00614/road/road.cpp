#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000002;
int n,m,k,f[N],dis[11][N],t[11][N],val[N],l,r,mn,sum,bh,ans,tot,res=LLONG_MAX;
struct nod{int u,v,w;}b[N],c[N];
inline bool cmp(nod x,nod y){return x.w<y.w;}
inline int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
signed main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i) cin>>b[i].u>>b[i].v>>b[i].w;
	sort(1+b,1+b+m,cmp);
	for(int i=1;i<=k;++i){cin>>val[i];for(int j=1;j<=n;++j) cin>>dis[i][j],t[i][j]=dis[i][j];}
	for(int i=1;i<=m;++i){
		l=find(b[i].u),r=find(b[i].v);
		if(l!=r) c[++tot]=b[i],f[r]=l;
	}for(int i=1;i<=n;++i) f[i]=i;
	for(int x=0;x<(1<<k);++x){
		for(int i=1;i<=10;++i) if(x&(1<<i-1)) ans+=val[i];
		for(int i=1;i<=tot;++i){
			l=find(c[i].u),r=find(c[i].v);
			mn=c[i].w,bh=0;
			for(int j=1;j<=k;++j){
				if(x&(1<<j-1)){
					sum=dis[j][l]+dis[j][r];
					if(sum<=mn) mn=sum,bh=j;
				}
			}ans+=mn,f[r]=l;
			if(bh) dis[bh][l]=0;
			for(int j=1;j<=k;++j) if(x&(1<<j-1)) dis[j][l]=min(dis[j][r],dis[j][l]);
		}res=min(res,ans),ans=0;
		for(int i=1;i<=n;++i) f[i]=i;
		for(int i=1;i<=k;++i) for(int j=1;j<=n;++j) dis[i][j]=t[i][j];
	}cout<<res;return 0;
}
