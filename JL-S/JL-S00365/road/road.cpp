#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=2000005;
int f[N],s[N];
int _find(int x){
    if(x==f[x])return x;
    return f[x]=_find(f[x]);
}
void _merge(int x,int y){
    int fx=_find(x),fy=_find(y);
    if(s[fx]>s[fy])swap(fx,fy);
    f[fx]=fy;
    s[fy]+=s[fx];
}
int num=0;
struct edge{
    int be,en,c;
}e[2000005];
bool operator < (edge a,edge b){
    return a.c>b.c;
}
priority_queue<edge>q,qq;
int ans=0;
int vis[N],cnt=100000000000000000;
void kruskal(){
    while(!q.empty()){
        //cout<<q.size()<<" "<<ans<<endl;
        edge v=q.top();
        q.pop();
        qq.push(v);
        int x=v.be,y=v.en;
        if(_find(x)==_find(y))continue;
        //cout<<vis[x]<<" "<<vis[y]<<" "<<x<<" "<<y<<" "<<ans<<endl;
        if(!vis[x]||!vis[y])continue;
        if(x)
        ans+=v.c;
        _merge(x,y);
    }
}
void dfs(int x){
    if(x==k+1)return ;
    for(int i=x;i<=k;i++){
        vis[x+n]=1;
        vis[x+n+n]=1;
        ans=0;
        for(int i=1;i<=3*n;i++){
            f[i]=i,s[i]=1;
        }
        while(!qq.empty()){
            q.push(qq.top());
            qq.pop();
        }
        kruskal();
        //cout<<ans<<endl;
        cnt=min(cnt,ans);
        dfs(x+1);
        vis[x]=0;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=3*n;i++){
        f[i]=i,s[i]=1;
    }
    for(int i=1;i<=n;i++)vis[i]=1;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        q.push({x,y,w});
        q.push({y,x,w});
    }
    kruskal();
    cnt=min(cnt,ans);
    for(int i=1;i<=k;i++){
        int o;
        cin>>o;
        //e[++num]={n+i,n+n+i,o};
        //e[++num]={n+n+i,n+i,o};
        q.push({n+i,n+n+i,o});
        q.push({n+n+i,n+i,o});
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            e[++num]={n+i,j,x};
            e[++num]={j,n+i,x};
            q.push({n+i,j,x});
            q.push({j,n+i,x});
        }
    }
    dfs(1);
    cout<<cnt<<endl;
    return 0;
}
