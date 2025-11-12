#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5,maxm=1e6+5;
const ll INF=1e10;
int n,m,k,cnt,f[maxn],sz[maxn],num,h[maxn][maxn],mp[15];
ll a[15][maxn],c[maxn];
ll dis[maxn][maxn],sum;
struct node{
    int u,v;
    ll d;
    int id;
}g[maxm];
inline int findd(int x){return ((f[x]==x)?x:f[x]=findd(f[x]));}
bool cmp(node aa,node bb){return aa.d<bb.d;}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            h[i][j]=h[j][i]=++cnt;
            g[cnt]={i,j};
            dis[i][j]=dis[j][i]=INF;
        }
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        ll w;
        cin>>w;
        dis[v][u]=dis[u][v]=w;
        g[h[u][v]]={u,v,w,0};
    }
    for(int p=1;p<=k;p++){
        cin>>c[p];
        for(int i=1;i<=n;i++)cin>>a[p][i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ll cur=a[p][i]+a[p][j]+c[p];
                if(dis[i][j]>cur){
                    dis[i][j]=dis[j][i]=cur;
                    g[h[i][j]]={i,j,cur,p};
                }
            }
                
        }
    }
    for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
    sort(g+1,g+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        int x=findd(g[i].u),y=findd(g[i].v);
        if(x==y)continue;
        if(sz[x]<sz[y])f[x]=y;
        else if(sz[x]==sz[y])f[x]=y,sz[x]++;
        else f[y]=x;
        sum+=g[i].d;
        mp[g[i].id]++;
        if((++num)==n-1)break;
    }
    for(int i=1;i<=k;i++){
        if(mp[i]<=1)continue;
        sum-=(ll)(mp[i]-1)*c[i];
    }
    cout<<sum<<"\n";
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/