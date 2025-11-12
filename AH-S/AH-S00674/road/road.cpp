#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e4+5,M=1e6+5;
struct Rode {
    LL s,t,w;
}b[M];
LL c[15],a[15][N],minn=0x3f3f3f3f3f3f3f3f,n,m,k;
bool vis[N];
bool check(){
    for(LL i=1;i<=n;i++){
        if(!vis[i]) return false;
    }
    return true;
}
void dfs(LL cur,LL sum){
    if(sum>=minn) return ;
    if(cur>m){
        if(check()){
            minn=min(minn,sum);
        }
        return ;
    }
    vis[b[cur].s]=true;
    vis[b[cur].t]=true;
    dfs(cur+1,sum+b[cur].w);
    vis[b[cur].s]=false;
    vis[b[cur].t]=false;
    dfs(cur+1,sum);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    LL u,v,w;
    bool fa=true;
    cin>>n>>m>>k;
    for(LL i=1;i<=m;i++){
        cin>>u>>v>>w;
        b[i].s=u;
        b[i].t=v;
        b[i].w=w;
    }
    for(LL i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0) fa=false;
        for(LL j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0) fa=false;
        }
    }
    if(fa){
        cout<<0;
        return 0;
    }
    for(LL i=1;i<=k;i++){
        for(LL j=1;j<=n;j++){
            for(LL l=1;l<=n;l++){
                for(LL o=1;o<=m;o++){
                    if(b[o].s==j&&b[o].t==l){
                        b[o].w=min(b[o].w,c[i]+a[i][j]+a[i][l]);
                        break;
                    }
                }
            }
        }
    }
    dfs(1,0);
    cout<<minn;
    return 0;
}
