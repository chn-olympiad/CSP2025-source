#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <random>
#include <time.h>
#define int long long
// #define ll long long
// #define db double
// #define db long double
// #define i128 __int128
#define pi pair<int,int>
#define fi first
#define se second

using namespace std;

const int N=1e4+20,M=1e6+10;

int T,n,m,k,p[N],sz[N],tot,ans,maxn;
bool flag[11];

struct edge{
    int from,to,val;
    bool operator < (const edge &b) const{
        return val<b.val;
    }
}E[M];
vector<edge> ord;

struct city{
    int cost;
    vector<int> g;
    bool operator < (const city &b) const{
        return cost<b.cost;
    }
}ci[11];

inline int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}

inline void merge(int a,int b){
    a=find(a),b=find(b);
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    p[b]=a;
    sz[a]+=sz[b];
}

inline void init(){
    sort(E+1,E+m+1);
    tot=n;
    for(int i(1);i<=n;++i){
        p[i]=i,sz[i]=1;
    }
    for(int i(1);i<=m;++i){
        int a=E[i].from,b=E[i].to,c=E[i].val;
        if(find(a)!=find(b)){
            merge(a,b);
            ans+=c;
            maxn=max(maxn,c);
            ord.push_back(E[i]);
            tot--;
            if(tot==1){
                break;
            }
        }
    }
}

inline void check(int now){
    int sum=now;
    vector<edge> e=ord;
    tot=n;
    for(int i(1);i<=n;++i){
        p[i]=i;
        sz[i]=1;
    }
    for(int i(1);i<=k;++i){
        if(!flag[i]){
            continue;
        }
        p[n+i]=n+i,sz[n+i]=1;
        tot++;
        for(int j(1);j<=n;++j){
            if(ci[i].g[j]>=maxn){
                continue;
            }
            e.push_back((edge){n+i,j,ci[i].g[j]});
        }
    }
    sort(e.begin(),e.end());
    for(auto t:e){
        int a=t.from,b=t.to,c=t.val;
        if(find(a)!=find(b)){
            merge(a,b);
            sum+=c;
            tot--;
            if(sum>=ans){
                return;
            }
            if(tot==1){
                break;
            }
        }
    }
    ans=min(ans,sum);
    return;
}

inline void dfs(int u,int now){
    if(now>=ans){
        return;
    }
    if(u==k+1){
        check(now);
        return;
    }
    flag[u]=false;
    dfs(u+1,now);
    flag[u]=true;
    dfs(u+1,now+ci[u].cost);
}

inline void sol(){
    cin>>n>>m>>k;
    for(int i(1);i<=m;++i){
        cin>>E[i].from>>E[i].to>>E[i].val;
    }
    for(int i(1);i<=k;++i){
        cin>>ci[i].cost;
        ci[i].g.push_back(0);
        for(int j(1),x;j<=n;++j){
            cin>>x;
            ci[i].g.push_back(x);
        }
    }
    sort(ci+1,ci+k+1);
    init();
    dfs(1,0);
    cout<<ans<<'\n';
    return;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>T;
    T=1;
    while(T--){
        sol();
    }
    return 0;
}