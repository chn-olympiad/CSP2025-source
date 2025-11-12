#include<bits/stdc++.h>
using namespace std;
struct edge{int u,v,w;}E[1000010],e[20][10010],b[20][10010],h[20010];
int n,m,k,tot,c[20],a[20][10010],p[10010],fa[10010],siz[10010],dis[10010];
long long ans=1e18,res=0,lst[20];
int top=0;
bool cmp(edge x,edge y){return x.w<y.w;}
int findfa(int now){
    if(!fa[now])return now;
    return fa[now]=findfa(fa[now]);
}
void add(int now){
    int x=1,y=1;
    for(int i=1;i<=n*2-2;i++){
        if(x<n&&(y==n||e[top][x].w<b[now][y].w))h[i]=e[top][x++];
        else h[i]=b[now][y++];
    }
    lst[top]=res;
    top++;res=0,tot=0;
    for(int i=1;i<=n;i++)fa[i]=0,siz[i]=1;
    for(int i=1;i<=n*2-2;i++){
        int fu=findfa(h[i].u),fv=findfa(h[i].v);
        if(fu!=fv){
            res+=h[i].w;
            e[top][++tot]=h[i];
            if(siz[fu]<siz[fv])swap(fu,fv);
            fa[fu]=fv;
            siz[fu]+=siz[fv];
        }
    }
}
void del(int now){
    res=lst[--top];
}
void dfs(int now,long long w){
    if(now==k+1){
        ans=min(ans,w+res);
        return;
    }
    dfs(now+1,w);
    add(now);
    dfs(now+1,w+c[now]);
    del(now);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        E[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int Min=2e9,pos=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]<Min)
                Min=a[i][j],pos=j;
        }
        c[i]+=Min;
        p[i]=pos;
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(j!=pos)
                b[i][++cnt]={pos,j,a[i][j]};
        sort(b[i]+1,b[i]+cnt+1,cmp);
    }
    sort(E+1,E+m+1,cmp);
    for(int i=1;i<=n;i++)siz[i]=1;
    for(int i=1;i<=m;i++){
        int fu=findfa(E[i].u),fv=findfa(E[i].v);
        if(fu!=fv){
            res+=E[i].w;
            e[0][++tot]=E[i];
            if(siz[fu]<siz[fv])swap(fu,fv);
            fa[fu]=fv;
            siz[fu]+=siz[fv];
        }
    }
    dfs(1,0);
    cout<<ans<<'\n';
    return 0;
}