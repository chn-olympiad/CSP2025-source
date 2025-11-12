#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000000000000ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep_(i,a,b) for(int i=(a);i<(b);i++)
#define per_(i,a,b) for(int i=(a);i>(b);i--)
#define N 10011
#define M 1000001
#define K 10
int n,m,k,u,v,w,fa[N],sz[N],tmp[M],c[K],fvr[M],a[K][N],dp[N][1<<K];
vector<tuple<int,int,int>>e,f,g[K];
void add(int u,int v,int w){
    e.emplace_back(w,u,v);
}
int grand(int x){
    return x==fa[x]?x:fa[x]=grand(fa[x]);
}
long long kruscal(){
    rep(i,1,n+k){
        fa[i]=i;
        sz[i]=1;
    }
    iota(fa+1,fa+n+k+1,1);
    fill(sz+1,sz+n+k+1,1);
    f.clear();
    long long ans=0;
    for(auto&i:e){
        int w=get<0>(i),u=get<1>(i),v=get<2>(i);
        int gu=grand(u),gv=grand(v);
        if(gu==gv){
            continue;
        }
        if(sz[gu]<sz[gv]){
            swap(gu,gv);
        }
        fa[gv]=gu;
        sz[gu]+=sz[gv];
        ans+=w;
        f.emplace_back(w,u,v);
    }
    e=move(f);
    return ans;
}
long long dfs(int x){
    if(x>k){
        return kruscal();
    }
    long long ans=dfs(x+1);
    auto tag=e;
    f.resize(e.size()+g[x].size());
    merge(e.begin(),e.end(),g[x].begin(),g[x].end(),f.begin());
    e=move(f);
    kruscal();
    long long ret=min(ans,dfs(x+1)+c[x]);
    e=tag;
    return ret;
}
void metasort(vector<tuple<int,int,int>>&e){
    rep_(i,0,e.size()){
        fvr[i]=get<0>(e[i]);
    }
    iota(tmp,tmp+e.size(),0);
    sort(tmp,tmp+e.size(),[&](int x,int y){return fvr[x]<fvr[y];});
    vector<tuple<int,int,int>>ret;
    ret.reserve(e.size());
    rep_(i,0,e.size()){
        ret.push_back(e[tmp[i]]);
    }
    e=move(ret);
}
void mian(int argt){
    cin>>n>>m>>k;
    e.reserve(m);
    while(m--){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    rep(i,1,k){
        cin>>c[i];
        g[i].reserve(n);
        rep(j,1,n){
            cin>>a[i][j];
            g[i].emplace_back(a[i][j],n+i,j);
        }
        metasort(g[i]);
    }
    metasort(e);
    kruscal();
    cout<<dfs(1)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;
    //cin>>T;
    rep(i,1,T){
        mian(i);
    }
}
/*
1. File IO
2. Array Size
3. Time
4. Memory
*/
