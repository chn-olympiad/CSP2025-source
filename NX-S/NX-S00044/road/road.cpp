// CSPS2025 - road
// Alea(322792)
#include <bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
const int N=2e4+5;
int n,m,k,fa[N],ans,sum,deg[N],c[15],a[15][N];
struct edge{
    int u,v,w;
};
vector<edge> gr,mst;
priority_queue<pair<int,int>> pq;
int find(int x){
    return fa[x]=(x==fa[x]?x:find(fa[x]));
}
bool merge(int x,int y){
    return ((x=find(x))==(y=find(y))?0:fa[x]=y);
}
auto cmp=[](edge x,edge y)->bool {return x.w<y.w;};
signed main(){
    fin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;++i) fin>>u>>v>>w,gr.push_back(edge{u,v,w});
    for(int i=1;i<=n;++i) fa[i]=i;
    sort(gr.begin(),gr.end(),cmp);
    for(auto ie:gr) if(merge(ie.u,ie.v)) mst.push_back(ie),ans+=ie.w;
    cerr<<ans<<endl;
    // 2^10 is only 1024.
    for(int i=1;i<=k;++i){
        fin>>c[i];
        for(int j=1;j<=n;++j) fin>>a[i][j];
    }
    for(int S=0;S<(1<<k);++S){
        sum=0,gr=mst;
        for(int i=1;i<=n+k;++i) fa[i]=i;
        for(int i=1;i<=k;++i) if(S&(1<<(i-1))){
            sum+=c[i];
            for(int j=1;j<=n;++j) gr.push_back({j,n+i,a[i][j]});
        }
        cerr<<sum<<" ";
        sort(gr.begin(),gr.end(),cmp);
        for(auto ie:gr) if(merge(ie.u,ie.v)) sum+=ie.w;
        cerr<<sum<<endl;
        ans=min(ans,sum);
    }
    fout<<ans<<endl;
    return 0;
}