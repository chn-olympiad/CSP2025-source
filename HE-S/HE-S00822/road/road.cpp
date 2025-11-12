#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+100;
int vis1[11],fa[N],n,m,k,c[11],a[11][N],ans=1e18;
struct edge{int u,v,w;}e[M],q[M];
inline int in(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') k=(k<<3)+(k<<1)+c-'0',c=getchar();
    return k*f;
}
inline bool operator<(edge a,edge b){return a.w<b.w;};
inline int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int work(){
    int nown=n;
    for(int i=1;i<=k;++i)
    if(vis1[i])
    nown++;
    int anss=0;
    int top1=1,top2=1,up=0;
    for(int i=1;i<=k;++i)
    if(vis1[i])
    {
        anss+=c[i];
        for(int j=1;j<=n;++j)
        q[++up]={n+i,j,a[i][j]};
    }
    for(int i=1;i<=n+k;++i) fa[i]=i;
    sort(q+1,q+up+1);
    int tot=0;
    while(tot<nown-1)
    {
        edge now;
        if(top1>m) now=q[top2++];
        else if(top2>up) now=e[top1++];
        else if(e[top1]<q[top2]) now=e[top1++];
        else now=q[top2++]; 
        if(find(now.u)==find(now.v)) continue;
        anss+=now.w;
        tot++;
        fa[find(now.u)]=find(now.v);
    }
    return anss;
}
void dfs(int pos){
    if(pos>k)
    {
        ans=min(ans,work());
        return;
    }
    vis1[pos]=0;
    dfs(pos+1);
    vis1[pos]=1;
    dfs(pos+1);
}
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    n=in(),m=in(),k=in();
    for(int i=1;i<=m;++i)
    e[i].u=in(),e[i].v=in(),e[i].w=in();
    sort(e+1,e+m+1);
    for(int i=1;i<=k;++i)
    {
        c[i]=in();
        for(int j=1;j<=n;++j)
        a[i][j]=in();
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
