#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5,K=15;
const ll inf=1e16;
int n,m,k,head[N*2],cnt1,cnt2,fa[N*2],c[K],vis[N*2];
ll ans,sum;
int read(){
    int x=0;char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
void write(ll x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct edge{
    int u,v,nxt,w;
}e1[M],e2[M];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void add1(int u,int v,int w){
    e1[++cnt1].u=u,e1[cnt1].v=v,e1[cnt1].w=w,e1[cnt1].nxt=head[u],head[u]=cnt1;
    return ;
}
void add2(int u,int v,int w){
    e2[++cnt2].u=u,e2[cnt2].v=v,e2[cnt2].w=w,e2[cnt2].nxt=head[u],head[u]=cnt2;
    return ;
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void kruskalpre(){
    sort(e1+1,e1+cnt1+1,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;  
    for(int i=1;i<=cnt1;i++){ 
        int fu=find(e1[i].u),fv=find(e1[i].v);
        if(fu==fv) continue;
        fa[fu]=fv;
        e2[++cnt2]=e1[i]; 
    }
    return ;
}
void kruskal(int x){
    for(int i=1;i<=n+k;i++) fa[i]=i;
    int tot=0;
    for(int i=1;i<=cnt2;i++){
        if(!vis[e2[i].u]) continue;
        int fu=find(e2[i].u),fv=find(e2[i].v);
        if(fu==fv) continue;
        fa[fu]=fv;
        sum+=e2[i].w; 
        ++tot;
        if(sum>ans) break;
        if(tot==x-1) break;
    }
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);  
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read(),v=read(),w=read();
        add1(u,v,w);
    }
    kruskalpre();
    for(int i=1;i<=k;i++){ 
        c[i]=read();
        for(int j=1;j<=n;j++){
            int a;
            a=read();
            add2(i+n,j,a);
        }
    } 
    sort(e2+1,e2+cnt2+1,cmp);
    ans=inf;
    for(int i=1;i<=n;i++) vis[i]=1;
    for(int i=0;i<(1<<k);i++){
        sum=0; 
        int ct=0;
        for(int j=0;j<k;j++){
            if((i>>j)&1){
                vis[n+j+1]=1;
                sum+=c[j+1];
                ++ct;
            }
        }
        kruskal(n+ct);
        ans=min(ans,sum);
        for(int j=0;j<k;j++){
            if((i>>j)&1) vis[n+j+1]=0;
        }
    }
    write(ans);
//    cerr<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}