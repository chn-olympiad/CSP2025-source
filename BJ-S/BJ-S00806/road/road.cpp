#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll n,m,k;
struct node{
    ll u,v,w;
}e[1000005],ne[10005],nne[10005];
bool cmp(node a,node b){
    return a.w<b.w;
}
ll c[15][10005],cc[15];
ll fa[10005];
ll sz[10005];
ll findr(ll x){
    return fa[x]==x?x:fa[x]=findr(fa[x]);
}
inline void merg(ll x,ll y){
    if(sz[x]>sz[y]){
        swap(x,y);
    }
    fa[x]=y;
    sz[y]+=sz[x];
}
bool vis[10005];
ll ans=0;
void dfs(ll x){
    if(x>k){
        ll res=0;
        for (int i=1;i<=k;i++){
            if(vis[i]){
                res+=cc[i];
            }
        }
        ll ntt=n-1;
        for (int i=1;i<n;i++){
            nne[i]=ne[i];
        }
        for (int i=1;i<=k;i++){
            if(vis[i]){
                for (int j=1;j<=n;j++){
                    nne[++ntt]=node{n+i,j,c[i][j]};
                }
            }
        }
        sort(nne+1,nne+ntt+1,cmp);
        ll cnt=0;
        for (int i=1;i<=n;i++){
            fa[i]=i;
            cnt++;
        }
        // cout<<"case:"<<ntt<<"\n";
        for (int i=1;i<=k;i++){
            if(vis[i]){
                // cout<<"#"<<i<<"\n";
                fa[i+n]=i+n;
                cnt++;
            }
        }
        cnt--;
        // cout<<cnt<<"\n";
        for (int i=1;i<=ntt;i++){
            ll fu=findr(nne[i].u),fv=findr(nne[i].v);
            // cout<<nne[i].u<<" "<<nne[i].v<<"\n";;
            if(fu==fv){
                continue;
            }
            // cout<<nne[i].u<<" "<<nne[i].v<<"\n";;
            res+=nne[i].w;
            merg(fu,fv);
            cnt--;
            if(!cnt){
                break;
            }
        }
        // cout<<"*"<<res<<"\n";
        ans=min(ans,res);
        return ;
    }
    vis[x]=0;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+m+1,cmp);
    for (int i=1;i<=k;i++){
        cin>>cc[i];
        for (int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        fa[i]=i;
    }
    ll tot=0;
    for (int i=1;i<=m;i++){
        ll fu=findr(e[i].u),fv=findr(e[i].v);
        if(fu==fv){
            continue;
        }
        ans+=e[i].w;
        ne[++tot]=e[i];
        merg(fu,fv);
    }
    // cout<<ans<<"\n";
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}