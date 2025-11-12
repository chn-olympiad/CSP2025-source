#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],cnt;
bool vis[10015];
struct DSU{
    int f[10015],dep[10015];
    void init(){
        iota(f+1,f+n+k+1,1);
    }
    int get(int x){
        while(x!=f[x])x=f[x]=f[f[x]];
        return x;
    }
    bool check(int u,int v){
        return get(u)==get(v);
    }
    void merge(int u,int v){
        u=get(u),v=get(v);
        if(dep[u]<dep[v])swap(u,v);
        if(dep[u]==dep[v])dep[u]++;
        f[v]=u;
    }
}d;
struct edge{
    int u,v,w;
    bool operator<(const edge&t)const{
        return w<t.w;
    }
}a[15][10005],e[1100005];
long long K(edge*e,int m,bool flag){
    d.init();
    long long sum=0,t=0;
    for(int i=0;i<m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(vis[u])continue;
        if(d.check(u,v))continue;
        d.merge(u,v);
        sum+=w;
        if(flag)e[++t]=e[i];
    }
    return sum;
}
int read(){
    int x(0),c(getchar());
    while(c<48)c=getchar();
    while(c>=48)x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        e[i]={read(),read(),read()};
    }
    stable_sort(e+1,e+m+1);
    K(e,m,1);
    cnt=n-1;
    long long ans=1e18;
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            e[++cnt]={n+i,j,read()};
        }
    }
    stable_sort(e+1,e+cnt+1);
    for(int i=n+1;i<=n+k;i++)vis[i]=1;
    for(int s=0;s<(1<<k);s++){
        long long sum=0;
        for(int i=1;i<=k;i++){
            if((s>>i-1)&1){
                sum+=c[i];
                vis[i+n]=0;
            }else vis[i+n]=1;
        }
        if(sum>=ans)break;
        ans=min(ans,sum+K(e,cnt,0));
    }
    cout<<ans<<"\n";
    return 0;
}