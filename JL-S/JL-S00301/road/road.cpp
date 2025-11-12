#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,k=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*k;
}
int n,m,k;
struct node{
    int u,v,w;
    bool operator<(const node& p)const{
        return w>p.w;
    }
};
priority_queue<node> q;
int xz[12][10003];
bool vis[12];
int ans,fa[10001];
int find(int u){
    if(u==fa[u])return u;
    return fa[u]=find(fa[u]);
}
void merge(int u,int v){
    fa[find(u)]=find(v);
}
void kruskal(){
    for(int i=1;i<=n;i++)fa[i]=i;
    int cnt=0;
    while(cnt<n-1){
        int u=q.top().u,v=q.top().v,w=q.top().w;q.pop();
        if(find(u)!=find(v)){
            cnt++;int minn=w,l=0;
            for(int i=1;i<=k;i++){
                if(vis[i])minn=min(minn,xz[i][u]+xz[i][v]);
                else{
                    if(minn>xz[i][0]+xz[i][u]+xz[i][v]){
                        l=i;minn=xz[i][0]+xz[i][u]+xz[i][v];
                    }
                }
            }
            if(l!=0)vis[l]=1;
            merge(u,v);
            ans+=minn;
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        node t;t.u=read();t.v=read();t.w=read();
        q.push(t);
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            xz[i][j]=read();
        }
    }
    kruskal();
    cout<<ans;
    return 0;
}

