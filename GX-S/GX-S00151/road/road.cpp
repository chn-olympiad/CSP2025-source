#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[11000],ki[12];
bitset<12>vis;
long long ans=1e18;
struct node{
    int u,v,w;
}bi[1050000];
int getin(int x){
    if(f[x]==x)return x;
    return getin(f[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
void dps(int u,int qk){
    vis[u]=qk;
    if(u!=k){
        dps(u+1,0),dps(u+1,1);
    }else{
        long long lans=0;
        for(int i=1;i<=n+k;i++)f[i]=i;
        for(int i=1;i<=k;i++)
            if(vis[i])lans+=ki[i];
        for(int i=1,x,y;i<=m;i++){
            if(bi[i].u>n&&!vis[bi[i].u%n])continue;
            x=getin(bi[i].u),y=getin(bi[i].v);
            if(x!=y){
                f[y]=x,lans+=bi[i].w;
                if(lans>=ans)return;
            }
        }
        ans=lans;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>bi[i].u>>bi[i].v>>bi[i].w;
    for(int i=1;i<=k;i++){
        cin>>ki[i];
        for(int j=1;j<=n;j++){
            cin>>bi[++m].w;
            bi[m].u=n+i,bi[m].v=j;
        }
    }
    sort(bi+1,bi+m+1,cmp);
    dps(1,0),dps(1,1);
    cout<<ans;
    return 0;
}
