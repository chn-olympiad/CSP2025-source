#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
    ll x,y,w;
}e[1100000];
bool cmp(edge A,edge B){return A.w<B.w;}
bool vis[15];
ll n,m,k,f[100100],v[15],ans=1e18;
int find(int z){
    return f[z]==z?z:f[z]=find(f[z]);
}
void dfs(ll now,ll use,ll fee){
    if(now==k+1){
        for(int i=1;i<=n+k;i++) f[i]=i;
        ll sum=0,cnt=0;
        for(int i=1;i<=m+n*k;i++){
            if(e[i].x>n&&!vis[e[i].x-n]) continue;
            int a=find(e[i].x),b=find(e[i].y);
            if(a!=b) {sum+=e[i].w;f[a]=b;cnt++;}
            if(cnt==use+n-1) break;
        }
        ans=min(ans,sum+fee);
        return;
    }
    if(use<k) {vis[now]=true;dfs(now+1,use+1,fee+v[now-1]);}
    vis[now]=false;
    dfs(now+1,use,fee);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].w);
    }
    for(int i=0;i<k;i++){
        scanf("%d",&v[i]);
        for(int j=1;j<=n;j++) {
            scanf("%lld",&e[m+n*i+j].w);
            e[m+n*i+j].x=n+i+1,e[m+n*i+j].y=j;
        }
    }
    sort(e+1,e+m+n*k+1,cmp);
    dfs(1,0,0);
    printf("%lld",ans);
    return 0;
}