#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
/*
Ren5Jie4Di4Ling5%
*/
int n,m,k;
const int M=1e6+50;
int sz;
struct edge{
    int u,v,w;
}a[2*M];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
bool vis[20];
int dad[2*M];
int c[20];
int ans=1e18;
int fd(int x){
    if(dad[x]==x)return x;
    return dad[x]=fd(dad[x]);
}
void merge1(int x1,int x2){
    int d1=fd(x1),d2=fd(x2);
    dad[d1]=d2;
}
void krus(){
    int ret=0;
    for(int i=1;i<=k;i++){
        if(vis[i])ret+=c[i];
    }
    for(int i=1;i<=sz;i++)dad[i]=i;
    for(int i=1;i<=sz;i++){
        if((a[i].u>n && !vis[a[i].u-n]) || (a[i].v>n && !vis[a[i].v-n]))continue;
        if(fd(a[i].u)==fd(a[i].v))continue;
        ret+=a[i].w;
        merge1(a[i].u,a[i].v);
    }
    ans=min(ans,ret);
}
void dfs(int x){
    if(x==k+1){
        krus();
        return;
    }
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[++sz]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int cost;
            cin>>cost;
            a[++sz]={n+i,j,cost};
        }
    }
    sort(a+1,a+1+sz,cmp);
    if(k==0){
        krus();
    }
    else dfs(1);
    cout<<ans;
}
