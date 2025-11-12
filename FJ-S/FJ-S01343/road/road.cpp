#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
using namespace std;
const int Siz=1<<18;char buf[Siz],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,Siz,stdin),p1==p2)?EOF:*p1++
int read(){
    int a=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') a=a*10+ch-'0',ch=getchar();
    return a;
}
const int N=1e4+10,M=1e6+10;
int n,m,k,fa[N],siz[N],c[12],cnt,ans,tr,nw[12];struct edge{int u,v,w;}a[M],g[12][N],e[M];bool vis[12];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int merge(int u,int v){
    int fu=getfa(u),fv=getfa(v);if(fu==fv) return cnt;cnt--;
    siz[fu]<siz[fv]?swap(fu,fv):void();fa[fv]=fu,siz[fu]+=siz[fv];return cnt;
}
void Init(int tot){
    cnt=tot;for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
}
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();for(int i=1;i<=m;i++) a[i]={read(),read(),read()};
    for(int i=1,j;i<=k;i++) for(c[i]=read(),j=1;j<=n;j++) g[i][j]={n+i,j,read()};
    Init(n);sort(a+1,a+m+1,[](edge a,edge b){return a.w<b.w;});
    for(int i=1;i<=k;i++) sort(g[i]+1,g[i]+n+1,[](edge a,edge b){return a.w<b.w;});
    int res=0,sum=0;for(int i=1;i<=m;i++) if(getfa(a[i].u)!=getfa(a[i].v)){
        res+=a[i].w;e[++tr]=a[i];if(merge(a[i].u,a[i].v)==1) break;
    }ans=res;for(int _=1;_<(1<<k);_++){
        res=0,sum=0;for(int i=1,q=_;i<=k;i++) vis[i]=(q&1),q>>=1,vis[i]?res+=c[i],sum++:0;
        int bk=0;for(int i=0;i<=k;i++) nw[i]=1;
        while(bk<n-1+sum*n){
            int mn=e[nw[0]].w;for(int i=1;i<=k;i++) if(vis[i]) mn=min(mn,g[i][nw[i]].w);
            if(mn==e[nw[0]].w) a[++bk]=e[nw[0]],nw[0]++;
            for(int i=1;i<=k;i++) if(vis[i]) if(mn==g[i][nw[i]].w) a[++bk]=g[i][nw[i]],nw[i]++;
        }
        Init(n+sum);for(int i=1;i<=bk;i++) if(getfa(a[i].u)!=getfa(a[i].v)){
            res+=a[i].w;if(merge(a[i].u,a[i].v)==1) break;
        }ans=min(ans,res);
    }return printf("%lld\n",ans),0;
    
}