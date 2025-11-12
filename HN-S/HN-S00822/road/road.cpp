#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxk = 20;
const int maxn = 1e4+114;
const int maxm = 1e6+114;
vector< pair<int,pair<int,int> > > mst[maxk];
vector< pair<int,pair<int,int> > > edge[maxk];
int fa[maxn];
int found(int u){
    return fa[u]=(fa[u]==u?u:found(fa[u]));
}
int n,m,k;
vector< pair<int,pair<int,int> > > vec;
int c[maxk];
int sz[maxn];
void chk(vector< pair<int,pair<int,int> > > &e){
    for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
    for(pair<int,pair<int,int> > now:e){
        int u=now.second.first,v=now.second.second;
        u=found(u),v=found(v);
        if(sz[u]>sz[v]) swap(u,v);
        //sz[u]<sz[v]
        if(u!=v){
            fa[u]=v;
            sz[v]+=sz[u];
            vec.push_back(now);
        }
    }
    swap(vec,e);
    vec.clear();
}
int ans=1e18;
void dfs(int h,int cst){
    if(h==k+1){
        int sum=0;
        for(pair<int,pair<int,int> > now:mst[h-1]){
            sum+=now.first;
        }
        ans=min(ans,sum+cst);
        return ;
    }
    //不放
    mst[h]=mst[h-1];
    dfs(h+1,cst);
    //放
    //mst[h]=mst[h-1]+edge[h]
    int tp0=0,tp1=0;
    mst[h].clear();
    while(tp0<mst[h-1].size()||tp1<edge[h].size()){
        if(tp0==mst[h-1].size()){
            mst[h].push_back(edge[h][tp1]);
            tp1++;
        }else if(tp1==edge[h].size()){
            mst[h].push_back(mst[h-1][tp0]);
            tp0++;
        }else if(mst[h-1][tp0].first<edge[h][tp1].first){
            mst[h].push_back(mst[h-1][tp0]);
            tp0++;
        }else{
            mst[h].push_back(edge[h][tp1]);
            tp1++;
        }
    }
    chk(mst[h]);
    dfs(h+1,cst+c[h]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mst[0].push_back(make_pair(w,make_pair(u,v)));
    }
    sort(mst[0].begin(),mst[0].end());
    chk(mst[0]);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            edge[i].push_back(make_pair(w,make_pair(n+i,j)));
        }
        sort(edge[i].begin(),edge[i].end());
    }
    dfs(1,0);
    cout<<ans<<"\n";
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