#include<bits/stdc++.h>
using namespace std;
int fa[11005];
int vis[15];
struct edge{
    int u,v,w;
}a[1500005],b[1500005];
int ep[15][10005];
int n,m,k;
long long sum=10000000000000;
time_t aa=clock();
void init(){
    for(int i=1;i<=11000;i++)fa[i]=i;
}
int fd(int x){
    return x==fa[x]?x:fa[x]=fd(fa[x]);
}
void mg(int x,int y){
    fa[fd(x)]=fd(y);
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
long long mst(){
    int cnt=m;
    long long ans=0;
    for(int i=1;i<=m;i++)a[i].u=b[i].u,a[i].v=b[i].v,a[i].w=b[i].w;
    for(int i=1;i<=k;i++){
        if(vis[i]){
            ans+=1ll*ep[i][0];
            for(int j=1;j<=n;j++){
                a[++cnt].u=n+i;a[cnt].v=j;a[cnt].w=ep[i][j];
            }
        }
    }
    sort(a+1,a+cnt+1,cmp);
    init();
    for(int i=1;i<=cnt;i++){
        if(fd(a[i].u)==fd(a[i].v))continue;
        ans+=1ll*a[i].w;
        mg(a[i].u,a[i].v);
    }
    sum=min(sum,ans);
        return ans;
}
void dfs(int x){
    time_t b=clock();
    if(b-aa>900000)return;
    if(x==k+1){
        sum=min(sum,mst());
        return;
    }

    long long s1=mst();
    vis[x]=1;
    long long s2=mst();
    if(s2<s1)dfs(x+1);
    vis[x]=0;
    dfs(x+1);
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>b[i].u>>b[i].v>>b[i].w;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++)cin>>ep[i][j];
    }
    for(int i=1;i<=k;i++)vis[i]=1;
    if(mst()==0ll){
        cout<<"0";return 0;
    }
    for(int i=1;i<=k;i++)vis[i]=0;
    dfs(1);
    cout<<sum;
    return 0;
}
