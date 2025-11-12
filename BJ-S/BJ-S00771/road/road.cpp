#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=3e6+5;
long long n,m,k,zans;
//vector<pair<int,int> > p[N];
long long a[20][N];
long long c[N];
long long fa[N];
struct edge{
    int u,v,w;
}e[M];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int fd(int x){
    if(fa[x]==x) return x;
    return fa[x]=fd(fa[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    zans=1e18;
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    long long cnt=0,ans=0;
    for(int i=0;i<(1<<k);++i){
        cnt=0;
        ans=0;
        for(int j=1;j<=k;++j){
            if(1<<(j-1)&i){
                ans+=c[j];
                for(int p=1;p<=n;++p){
                    ++cnt;
                    e[m+cnt]={n+j,p,a[j][p]};
                }
            }
        }
        for(int i=1;i<=n+k;++i) fa[i]=i;
        sort(e+1,e+cnt+m,cmp);
        for(int i=1;i<=m+cnt;++i){
            int fu=fd(e[i].u),fv=fd(e[i].v);
            if(fu!=fv){
                ans+=e[i].w;
                fa[fu]=fv;
            }
        }
        zans=min(zans,ans);
    }
    cout<<zans;
    return 0;
}
