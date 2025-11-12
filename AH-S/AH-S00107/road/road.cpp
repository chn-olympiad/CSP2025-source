#include<bits/stdc++.h>
using namespace std;
struct node{int u,v,w;}e[1000015],e1[1000015];
int n,m,k,f[1000015],c,t[1000015];
long long ans=1e18;
bool cmp(node a,node b){return a.w<b.w;}
int getf(int x){return f[x]<0?x:(f[x]=getf(f[x]));}
inline void mg(int u,int v){
    if(f[u]<f[v])f[u]+=f[v],f[v]=u;
    else f[v]+=f[u],f[u]=v;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=n;i++)f[i]=-1;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=getf(e[i].u),v=getf(e[i].v);
        if(u==v)continue;
        mg(u,v);
        e1[++c].u=e[i].u;
        e1[c].v=e[i].v;
        e1[c].w=e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>t[i];
        for(int j=1,x;j<=n;j++){
            cin>>x;
            e1[++c]=(node){i+n,j,x};
        }
    }
    sort(e1+1,e1+c+1,cmp);
    for(int i=0;i<(1<<k);i++){
        long long s=0;
        for(int j=1;j<=n+k;j++)f[j]=-1;
        for(int j=1;j<=k;j++){
            if((i>>j-1)&1)s+=t[j];
        }
        for(int j=1;j<=c;j++){
            if(e1[j].u>n&&!(i&(1<<e1[j].u-n-1)))continue;
            int u=getf(e1[j].u),v=getf(e1[j].v);
            if(u==v)continue;
            mg(u,v);
            s+=e1[j].w;
        }
        ans=min(ans,s);
    }
    cout<<ans;
    return 0;
}
