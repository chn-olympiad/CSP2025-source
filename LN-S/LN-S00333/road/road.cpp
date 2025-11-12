#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6+5;
struct edge{
    int u,v,w,id;
}e[N],ed[N];
int n,m,k,cnt,num,c[N],fa[N];
bool vis[N];
ll sum,ans;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int read(){
    int k=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        k=k*10+ch-'0',ch=getchar();
    return k;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void build(){
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v)
            continue;
        else{
            ed[++cnt]=e[i];
            fa[v]=u;
            ans+=e[i].w;
        }
    }
}
void solve(int s){
    sum=0,num=n;
    for(int i=1;i<=n+k;i++)
        fa[i]=i;
    for(int i=1;i<=k;i++){
        if(s&(1<<(i-1))){
            vis[n+i]=true;
            sum+=c[i];
            num++;
        }
        else
            vis[n+i]=false;
    }
    if(sum>=ans) return;
    for(int i=1;i<=cnt;i++){
        if(!vis[ed[i].u])
            continue;
        int u=find(ed[i].u),v=find(ed[i].v);
        if(u==v)
            continue;
        else{
            num--;
            fa[v]=u;
            sum+=ed[i].w;
        }
        if(sum>=ans)
            return;
        if(num==1)
            break;
    }
    ans=min(ans,sum);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int w;
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
        e[i].u=read(),e[i].v=read(),e[i].w=read();
    build();
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            w=read();
            ed[++cnt]=(edge){n+i,j,w,i};
        }
    }
    sort(ed+1,ed+1+cnt,cmp);
    for(int i=1;i<=n;i++)
        vis[i]=true;
    for(int i=0;i<(1<<k);i++)
        solve(i);
    printf("%lld",ans);
    return 0;
}