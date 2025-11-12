#include<bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
const int N=10011,M=1000001;
int n,m,k;
struct edge{
    int u,v,w;
}e[M],g[N*11];
il bool cmp(edge i,edge j){
    return i.w<j.w;
}
int f[N];
il int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
int c[11];
bool v[11];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1,cmp);
    ll ans=0;
    for(int i=1;i<=n;i++)f[i]=i;
    int mm=0;
    for(int i=1;i<=m;i++){
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv)continue;
        ans+=e[i].w;
        g[++mm]=e[i];
        f[fu]=fv;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>g[++mm].w;
            g[mm].u=n+i,g[mm].v=j;
        }
    }
    sort(g+1,g+mm+1,cmp);
    for(int s=1;s<(1<<k);s++){
        ll sum=0;
        for(int i=1;i<=k;i++){
            v[i]=(s>>(i-1))&1;
            if(v[i])sum+=c[i];
        }
        for(int i=1;i<=n+k;i++)f[i]=i;
        for(int i=1;i<=mm;i++){
            if(g[i].u>n&&!v[g[i].u-n])continue;
            int fu=find(g[i].u),fv=find(g[i].v);
            if(fu==fv)continue;
            sum+=g[i].w;
            f[fu]=fv;
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
