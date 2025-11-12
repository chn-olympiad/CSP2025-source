#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+10;
const int INF=2e9;
int fa[N+5],sz[N+5],c[10];
pair<int,int> wi[N+5][1<<10];
vector<int> cf[N+5][10];
vector<tuple<int,int,int> > edges[1<<10];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
bool join(int x,int y){
    x=getfa(x),y=getfa(y);
    if(x==y) return false;
    if(sz[x]>sz[y]) swap(x,y);
    fa[x]=y;
    sz[y]+=sz[x];
    return true;
}
int lowbit(int x){
    return x&(-x);
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[0].push_back({w,u,v});
    }
    sort(edges[0].begin(),edges[0].end());
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
    }
    long long ans,ans1=0;
    for(auto id:edges[0]){
        int w=get<0>(id),u=get<1>(id),v=get<2>(id);
        if(join(u,v)){
            ans1+=w;
            edges[1].emplace_back(id);
        }
    }
    ans=ans1;
    swap(edges[0],edges[1]);
    edges[1].clear();
    //edges[1].shrink_to_fit();
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>wi[j][1<<i].first;
            wi[j][1<<i].second=i;
            edges[0].push_back({wi[j][(1<<i)].first,i+n+1,j});
        }
    }
    for(int i=1;i<=n;i++){
        wi[i][0]={INF,0};
        for(int j=1;j<(1<<k);j++){
            wi[i][j]=min(wi[i][j^lowbit(j)],wi[i][lowbit(j)]);
            cf[i][wi[i][j].second].emplace_back(j);
        }
    }
    sort(edges[0].begin(),edges[0].end());
    for(auto id:edges[0]){
        int w=get<0>(id),u=get<1>(id),v=get<2>(id);
       // cout<<w<<" "<<u<<" "<<v<<"\n";
        if(u>n){
            for(int j:cf[v][u-n-1]){
                edges[j].push_back({w,u,v});
            }
        }
        else{
            for(int i=1;i<(1<<k);i++){
                edges[i].emplace_back(id);
            }
        }
    }
    for(int j=1;j<(1<<k);j++){
        for(int i=1;i<=n+k+1;i++){
            fa[i]=i;
            sz[i]=1;
        }
        ans1=0;
        for(int i=0;i<k;i++){
            if((j>>i)&1){
                ans1+=c[i];
          //      cout<<i+1<<" ";
            }
        }
        //cout<<ans1<<"\n";
        for(auto id:edges[j]){
            int w=get<0>(id),u=get<1>(id),v=get<2>(id);
            //cout<<w<<" "<<u<<" "<<v<<"\n";
            if(join(u,v)){
                ans1+=w;
            }
        }

        ans=min(ans,ans1);
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Tcases=1;
    //cin>>Tcases;
    while(Tcases--) solve();
    return 0;
}
