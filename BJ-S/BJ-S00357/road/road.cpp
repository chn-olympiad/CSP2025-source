#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar_unlocked();
}
template<typename T>
void write(T x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e4+15,M=2e6+5;
int n,m,k;
int a[11][N],c[11],aa[11][N];
int dis[N];
bool vis[N];
struct edge{
    int v,w;
};
struct Edge{
    int u,v,w;
}e[M];
vector<edge>g[N];
struct node{
    int u,dis;
    friend bool operator<(node a,node b){
        return a.dis>b.dis;
    }
};
inline int prim(int n){
    int ans=0;
    rep(i,1,n) dis[i]=1000000000000000000ll,vis[i]=0;
    priority_queue<node>q;
    dis[1]=0,q.push({1,0});
    while(!q.empty()){
        int u=q.top().u;q.pop();
        if(vis[u]) continue;
        vis[u]=1,ans+=dis[u];
        for(edge i:g[u]){
            int v=i.v,w=i.w;
            if(w<dis[v]){
                dis[v]=w;
                q.push({v,dis[v]});
            }
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    rep(i,1,m){
        int u,v,w;
        read(u),read(v),read(w);
        e[i]={u,v,w};
    }
    rep(i,1,k){
        read(c[i]);
        rep(j,1,n) read(a[i][j]);
    }
    if(k<=0){
        rep(i,1,m){
            g[e[i].u].push_back({e[i].v,e[i].w});
            g[e[i].v].push_back({e[i].u,e[i].w});
        }
        write(prim(n));
    }else{
        int ans=9000000000000000000ll;
        rep(s,0,(1<<k)-1){
            int tot=m,cnt=n,sum=0;
            rep(i,1,n+k) g[i].clear();
            rep(i,1,m){
                g[e[i].u].push_back({e[i].v,e[i].w});
                g[e[i].v].push_back({e[i].u,e[i].w});
            }
            rep(i,0,k-1) if(s>>i&1){
                int id=i+1;++cnt,sum+=c[id];
                rep(j,1,n){
                    g[cnt].push_back({j,a[id][j]});
                    g[j].push_back({cnt,a[id][j]});
                }
            }
            ans=min(ans,prim(cnt)+sum);
        }
        write(ans);
    }
    // cerr<<"time:"<<1.0*clock()/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
/*
g++ T1.cpp -o T1 -std=c++14 -O2 
ctrl+` to open
*/