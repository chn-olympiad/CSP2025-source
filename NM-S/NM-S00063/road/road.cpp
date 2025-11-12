#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const ll INF=0x3f3f3f3f3f3f3f3f;
const int M=1200005;
const int N=12005;
inline int read(){
    int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
ll ans=0,res=INF;
int n,m,k,c[N],vis[N],arr[N],dsu[N];
inline int getfather(int u){
    if(u==dsu[u])return u;
    return dsu[u]=getfather(dsu[u]);
}
inline void unite(int u,int v){dsu[getfather(u)]=getfather(v);}
struct stt{int u,v,w;}bian[M];
inline bool cmp(stt x,stt y){return x.w<y.w;}
vector<pii> edgs[N];
struct st{
    int u,w;
    bool operator<(const st &rhs)const{
        return w>rhs.w;
    }
};
inline void prim(int e){
    priority_queue<st> q;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(pii v:edgs[1]){
        if(!arr[v.fi])continue;
        q.push({v.fi,v.se});
    }
    while(!q.empty()){
        st u=q.top();q.pop();
        if(vis[u.u])continue;
        vis[u.u]=1;ans+=u.w;
        for(pii v:edgs[u.u]){
            if(!arr[v.fi]||vis[v.fi])continue;
            q.push({v.fi,v.se});
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=n;++i)dsu[i]=i;
    for(int i=1;i<=m;++i){bian[i].u=read();bian[i].v=read();bian[i].w=read();}
    sort(bian+1,bian+1+m,cmp);
    for(int i=1;i<=m;++i){
        if(getfather(bian[i].u)!=getfather(bian[i].v)){
            edgs[bian[i].u].push_back(mp(bian[i].v,bian[i].w));
            edgs[bian[i].v].push_back(mp(bian[i].u,bian[i].w));
            unite(bian[i].u,bian[i].v);
        }
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1,w;j<=n;++j){
            w=read();
            edgs[j].push_back(mp(i+n,w));
            edgs[i+n].push_back(mp(j,w));
        }
    }
    for(int i=1;i<=n;++i)arr[i]=1;
    for(int i=0;i<(1<<k);++i){
        ans=0;
        for(int j=1;j<=k;++j){
            if((i>>j-1)&1)ans+=c[j],arr[j+n]=1;
            else arr[j+n]=0;
        }
        prim(i);
        res=min(res,ans);
    }
    cout<<res;
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
