#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,INF=1e18;
int fa[N],siz[N],sum,mn[N],p[N],a[15][N],faw[N],c[N];

struct node{
    int v,w;

};

struct nod{
    int u,v,w;

    inline friend bool operator < (nod a,nod b){
        return a.w<b.w;
    }
};

vector<node>e[N];
priority_queue<nod>q,qq;
vector<nod>tmp;

inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}

inline void write(int x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

inline void merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return ;
    if(siz[a]<siz[b]) swap(a,b);
    siz[a]+=siz[b];
    fa[b]=a;
}

inline void gettree(){
    while(!q.empty()){
        int u=q.top().u,v=q.top().v,w=q.top().w;
        q.pop();
        if(find(u)==find(v)) continue;
        sum-=w;
        e[u].push_back({v,-w}),e[v].push_back({u,-w});
        merge(u,v);
    }
}

inline void gettree1(){
    while(!qq.empty()){
        int u=qq.top().u,v=qq.top().v,w=qq.top().w;
        qq.pop();
        if(find(u)==find(v)) continue;
        sum-=w;
        e[u].push_back({v,-w}),e[v].push_back({u,-w});
        merge(u,v);
    }
}


inline void dfs(int u,int fz){
    for(auto [v,w]:e[u]){
        if(v==fz) continue;
        tmp.push_back({u,v,-w});
        faw[v]=w;
        dfs(v,u);
    }
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        q.push({u,v,-w});
        // tmp.push_back({u,v,w});
    }
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
    gettree();
    for(int i=0;i<k;i++){
        c[i]=read();
        p[i]=0;
        a[i][0]=INF;
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            if(a[i][j]<a[i][p[i]]) p[i]=j;
        }
    }
    dfs(1,0);
    int ans=sum;
    for(int i=0;i<(1<<k);i++){
        while(!qq.empty()) qq.pop();
        for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
        int sumc=0;
        for(int j=0;j<k;j++){
            if(!((i>>j)&1)) continue;
            sumc+=c[j];
            for(int k=1;k<=n;k++){
                qq.push({j+n+1,k,-a[j][k]});
            }
        } 
        for(auto [u,v,w]:tmp) qq.push({u,v,w});
        sum=0;
        gettree1();
        ans=min(ans,sum+sumc);
    }
    printf("%lld\n",ans);
    // int ans=sum;
    // for(int i=0;i<(1<<k);i++){
    //     for(int j=1;j<=n;j++) mn[j]=faw[j];
    //     int sumc=0,summn=0;
    //     for(int j=0;j<k;j++){   
    //         if(!((i>>j)&1)) continue;
    //         mn[p[j]]=min(mn[p[j]],a[j][1]);
    //         for(int l=2;l<=n;l++){
    //             if(l==p[j]) continue;
    //             mn[l]=min(mn[l],a[j][l]);
    //         }
    //         sumc+=c[j],summn+=a[j][p[j]];
    //     }
    //     int tmp=sumc+summn;
    //     for(int i=2;i<=n;i++){
    //         tmp+=mn[i];
    //     }
    //     ans=min(ans,tmp);
    // }
    // printf("%lld\n",ans);
    return 0;
}