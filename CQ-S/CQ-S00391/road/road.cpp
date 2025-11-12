#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
template<typename T> inline void read(T &x){x=0;int f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();x*=f;}
template<typename T> inline void write(T x){if(x>9)write(x/10);putchar(x%10+'0');}
const int N=1e4+10,M=1e6+10;
int n,m,k,fa[N],c[11],a[11][N],siz[N],vis[11];
// int head[N],cnt;
ll ans;
struct edge{int u,v,w,id;}G[M<<1],tmp[M<<1];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
// struct node{int to,w,id,next;}e[N<<1];
// void add(int u,int v,int w,int id){
//     e[++cnt].to=v,e[cnt].w=w,e[cnt].next=head[u],e[cnt].id=id,head[u]=cnt;
// }
// set<int> s,s2;
// void dfs(int u,int f,int st){
//     for(int i=head[u],v;i;i=e[i].next){
//         v=e[i].to;
//         if(v==f)continue;
//         if(e[i].w>a[st][v])s2.insert(v)/*,cout<<"??"<<v<<"\n"*/,delta+=e[i].w-a[st][v];
//         else s.insert(e[i].id);
//         dfs(v,u,st);
//     }
// }
ll MST(int mx){
    ll res=0;
    sort(G+1,G+1+m,[&](edge x,edge y){return x.w<y.w;});
    for(int i=1;i<=mx;++i)fa[i]=i,siz[i]=1;
    for(int i=1;i<=10;++i)vis[i]=0;
    int len=0;
    for(int i=1;i<=m&&len<mx-1;++i){
        if(G[i].id&&!vis[G[i].id]){
            int w=G[i+1].w;
            if(G[i+1].id&&!vis[G[i+1].id])w+=c[G[i+1].id];
            if(w<G[i].w+c[G[i].id]){
                swap(G[i],G[i+1]);
            }
        }
        int u=find(G[i].u),v=find(G[i].v);
        if(u==v)continue;
        if(siz[u]>siz[v])swap(u,v);
        fa[u]=v,siz[v]+=siz[u],res+=G[i].w;
        vis[G[i].id]=1,++len,tmp[len]=G[i];
        // add(G[i].u,G[i].v,G[i].w,i),add(G[i].v,G[i].u,G[i].w,i);
    }
    for(int i=1;i<=len;++i)G[i]=tmp[i];
    m=len;
    for(int i=1;i<=10;++i)if(vis[i])res+=c[i];
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1;i<=m;++i)read(G[i].u),read(G[i].v),read(G[i].w),G[i].id=0;
    for(int i=1;i<=k;++i){
        read(c[i]);
        for(int j=1;j<=n;++j)read(a[i][j]);
    }
    ans=MST(n);
    // ans=inf;
    for(int u=1;u<=k;++u){
        // s.clear(),s2.clear(),delta=0,dfs(u,0,u);
        // if(delta>c[u]){
        //     for(int i=1;i<=n;++i)head[i]=0;
        //     cnt=0;
        //     for(auto x:s)add(G[x].u,G[x].v,G[x].w,x),add(G[x].v,G[x].u,G[x].w,x);
        //     for(auto x:s2)G[++m]={u,x,a[u][x]},add(u,x,a[u][x],m),add(x,u,a[u][x],m);
        //     ans-=delta-c[u];
        //     // cout<<"!!"<<u<<" "<<delta<<" "<<ans<<"\n";
        // }
        for(int i=1;i<=n;++i)G[++m]={n+u,i,a[u][i],u};
        ll res=MST(n+u);
        ans=min(ans,res);
    }
    write(ans);
    return 0;
}