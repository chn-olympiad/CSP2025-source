#include <bits/stdc++.h>
#define N 1000002
#define M 1030
#define K 10022
#define ll long long
using namespace std;
const ll inf=1e12;
int n,m,k,fa[K],cnt;
ll c[M],ans,a[12][K],b[K],res=inf;
struct node{
    int u,v;ll w;
}e[N],e2[N],e3[N];
bool operator <(node a,node b){
    return a.w<b.w;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve(){
    sort(e2+1,e2+m+1);
    for(int i=1;i<=m;i++){
        if(cnt==n-1)  break;
        int u=e2[i].u,v=e2[i].v;
        int fu=find(u),fv=find(v);
        if(fu==fv)  continue;
        fa[fu]=fv;
        e[++cnt]={u,v,e2[i].w};
    }
}
void solve2(int n){
    sort(e3+1,e3+m+1);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(cnt==n-1)  break;
        int u=e3[i].u,v=e3[i].v;
        int fu=find(u),fv=find(v);
        if(fu==fv)  continue;
        fa[fu]=fv;
        // cout<<u<<" "<<v<<"\n";
        cnt++;
        ans+=e3[i].w;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int j=1;j<=n;j++)  fa[j]=j;
    for(int i=1;i<=m;i++)  cin>>e2[i].u>>e2[i].v>>e2[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)  cin>>a[i][j];
    }
    solve();
    for(int i=0;i<(1<<k);i++){
        ans=0,m=0;
        int tmp=0;
        for(int j=1;j<=n+k;j++){
            b[j]=inf;
            fa[j]=j;
        }
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                tmp++;
                ans+=c[j];
                for(int p=1;p<=n;p++)  e3[++m]={n+j,p,a[j][p]};
            }
        }
        for(int j=1;j<n;j++)  e3[++m]={e[j].u,e[j].v,e[j].w};
        solve2(n+tmp);
        res=min(res,ans);
        // cout<<ans<<" ";
    }
    cout<<res<<"\n";
    return 0;
}