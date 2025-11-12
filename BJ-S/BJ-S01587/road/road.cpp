#include<bits/stdc++.h>
#define int long long
using namespace std;
bool zpd=1;
int n,m,k,fa[10005],c[15],d[15][10005],tot=0,ans=1e18,dis[10005],vis[10005];
struct A{
    int x,y,z;
}a[1000005],b[200005];
bool cmp(A a,A b){
    return a.z<b.z;
}
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
struct B{
    int to,w;
};
vector<B> v[10005];
struct C{
    int p,x;
};
bool operator <(C a,C b){
    return a.x>b.x;
}
priority_queue<C> q;
int pr(int y){
    int minn=1e18,tmp,ret=0;
    for(int i=1;i<=tot;i++){
        if(b[i].z<minn)minn=b[i].z,tmp=b[i].x;
        v[b[i].x].push_back({b[i].y,b[i].z});
        v[b[i].y].push_back({b[i].x,b[i].z});
    }
    for(int i=1;i<=n+y;i++)dis[i]=1e18;
    q.push({tmp,0});
    while(!q.empty()){
        int p=q.top().p,x=q.top().x;
        q.pop();
        if(vis[p])continue;
        vis[p]=1;
        ret+=x;
        for(int i=0;i<v[p].size();i++){
            if(!vis[v[p][i].to]){
                if(dis[v[p][i].to]>v[p][i].w)dis[v[p][i].to]=v[p][i].w,q.push({v[p][i].to,v[p][i].w});
            }
        }
    }
    for(int i=1;i<=n+y;i++)v[i].clear(),vis[i]=0;
    return ret;
}
void dfs(int p,int x,int y){
    if(p==k+1){
        ans=min(ans,x+pr(y));
        return;
    }
    for(int i=1;i<=n;i++)tot++,b[tot].x=n+y+1,b[tot].y=i,b[tot].z=d[p][i];
    dfs(p+1,x+c[p],y+1);
    tot-=n;
    if(!zpd)dfs(p+1,x,y);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])zpd=0;
        for(int j=1;j<=n;j++)cin>>d[i][j];
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=find(a[i].x),y=find(a[i].y);
        if(x==y)continue;
        b[++tot]=a[i];
        fa[x]=y;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
