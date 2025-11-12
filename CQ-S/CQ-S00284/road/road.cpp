#include<bits/stdc++.h>
#define N 10015
#define M 1000005
#define ll long long
using namespace std;
pair<int,pair<int,int>>Edge[M];
int n,m,k,c[15],id[15],p[15];
ll Ans=1e18;
struct DSU{
    int fa[N],sz[N];
    inline void init(int x){
        for(int i=1;i<=x;i++){
            fa[i]=i;sz[i]=1;
        }
    }
    inline int find(int x){
        if(fa[x]==x){
            return x;
        }return fa[x]=find(fa[x]);
    }
    inline void merge(int x,int y){
        x=find(x);y=find(y);
        if(x!=y){
            if(sz[x]>sz[y]){
                swap(x,y);
            }fa[x]=y;sz[y]+=sz[x];
        }
    }
}Dsu;
pair<int,int>Edge2[11][N];
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>Edge[i].second.first>>Edge[i].second.second>>Edge[i].first;
    }sort(Edge+1,Edge+1+m);
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>Edge2[i][j].first;Edge2[i][j].second=j;
        }sort(Edge2[i]+1,Edge2[i]+1+n);
    }
    Dsu.init(n);vector<pair<int,pair<int,int>>>edges;
    for(int i=1;i<=m;i++){
        int x=Edge[i].second.first,y=Edge[i].second.second,val=Edge[i].first;
        if(Dsu.find(x)!=Dsu.find(y)){
            edges.push_back(Edge[i]);
            Dsu.merge(x,y);
        }
    }
    for(int i=1;i<n;i++){
        Edge[i]=edges[i-1];

    }
    for(int msk=0;msk<(1<<k);msk++){
        ll ans1=0;int oth=0;
        for(int i=0;i<k;i++){
            if(msk>>i&1){
                p[oth]=i;oth++;
                ans1+=c[i];
            }
        }
        for(int i=0;i<=oth;i++){
            id[i]=1;
        }
        int cnte=0;
        Dsu.init(n+k);
        while(cnte<n+oth-1){
            int ret=1e9;
            for(int i=0;i<oth;i++){
                if(id[i]<=n){
                    ret=min(ret,Edge2[p[i]][id[i]].first);
                }
            }
            if(id[oth]<n){
                ret=min(ret,Edge[id[oth]].first);
            }int idw=oth;
            for(int i=0;i<oth;i++){
                if(id[i]<=n&&Edge2[p[i]][id[i]].first==ret){
                    idw=i;break;
                }
            }int x,y,val;
            if(idw==oth){
                x=Edge[id[oth]].second.first,y=Edge[id[oth]].second.second;val=Edge[id[oth]].first;
                id[oth]++;
            }else{
                x=Edge2[p[idw]][id[idw]].second;y=p[idw]+n+1;val=Edge2[p[idw]][id[idw]].first;
                id[idw]++;
            }
            if(Dsu.find(x)!=Dsu.find(y)){
                ans1+=val;Dsu.merge(x,y);cnte++;
            }
        }
        Ans=min(Ans,ans1);
    }cout<<Ans<<endl;
}
