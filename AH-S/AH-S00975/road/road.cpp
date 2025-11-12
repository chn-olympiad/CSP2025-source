#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=10100;
struct way{
    int s,e,w;
}a[2000005+N*2],b[2000005+N*2];
int n,m,k,fa[N],c[15][N],tmp;
ll ans=0x3f3f3f3f3f3f3f3f;
void init(){
    for(int i=1;i<=tmp;i++){
        fa[i]=i;
    }
}
int find(int u){
    if(fa[u]!=u){
        return fa[u]=find(fa[u]);
    }
    return u;
}
bool same(int u,int v){
    return find(u)==find(v);
}
void unite(int u,int v){
    u=find(u),v=find(v);
    if(u!=v){
        fa[v]=u;
    }
}
void add(int x,int m){
    for(int i=1;i<=n;i++){
        a[m+i].s=n+x,a[m+i].e=i,a[m+i].w=c[x][i];
    }
}
bool cmp(way u,way v){
    return u.w<v.w;
}
ll answer(){
    init();
    ll sum=0;
    for(int i=1;i<=m;i++){
        b[i]=a[i];
    }
    sort(b+1,b+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(!same(b[i].s,b[i].e)){
            //cout<<i<<' ';
            unite(b[i].s,b[i].e);
            sum+=b[i].w;
        }
    }
    return sum;
}
void dfs(int x,ll cost){
    if(x>k){
        ans=min(ans,cost+answer());
        return;
    }
    add(x,m);
    m+=n,tmp++;
    dfs(x+1,cost+c[x][0]);
    m-=n,tmp--;
    dfs(x+1,cost);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>a[i].s>>a[i].e>>a[i].w;
    }
    tmp=n;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
        }
    }
    dfs(1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
