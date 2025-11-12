#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,M=1e6+1,K=11;
int cn,m,k;
struct edge{
    int u,v;
    long long w;
}e[M],o[K*N];
int tot;
bool cmp(edge A,edge B){
    return A.w<B.w;
}
long long val[K],vis;
int fa[N+K],sz[N+K];
long long ans=1e18;
int get(int x){
    if(!fa[x]) return x;
    return fa[x]=get(fa[x]);
}
void solve(){
    int n=cn;
    long long res=0;
    for(int i=1;i<=k;++i){
        if((vis>>(i-1))&1) ++n,res+=val[i];
    }
    int cnt=0;
    for(int i=1;i<=cn+k;++i) fa[i]=0,sz[i]=1;
    int j=1;
    for(int i=1;i<=tot;++i){
        if(!((vis>>(o[i].u-1))&1)) continue;
        while(j<=m&&e[j].w<=o[i].w){
            int u=e[j].u,v=e[j].v;
            long long w=e[j].w;
            int fu=get(u),fv=get(v);
            ++j;
            if(fu==fv) continue;
            res+=w;
            if(sz[fu]>sz[fv]){
                sz[fu]+=sz[fv];
                fa[fv]=fu;
            }
            else{
                sz[fv]+=sz[fu];
                fa[fu]=fv;
            }
            ++cnt;
            if(cnt==n-1) break;
        }
        if(cnt==n-1) break;
        int u=o[i].u+cn,v=o[i].v;
        long long w=o[i].w;
        int fu=get(u),fv=get(v);
        if(fu==fv) continue;
        res+=w;
        if(sz[fu]>sz[fv]){
            sz[fu]+=sz[fv];
            fa[fv]=fu;
        }
        else{
            sz[fv]+=sz[fu];
            fa[fu]=fv;
        }
        ++cnt;
        if(cnt==n-1) break;
    }
    while(cnt<n-1){
        int u=e[j].u,v=e[j].v;
        long long w=e[j].w;
        int fu=get(u),fv=get(v);
        ++j;
        if(fu==fv) continue;
        res+=w;
        if(sz[fu]>sz[fv]){
            sz[fu]+=sz[fv];
            fa[fv]=fu;
        }
        else{
            sz[fv]+=sz[fu];
            fa[fu]=fv;
        }
        ++cnt;
    }
    ans=min(ans,res);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>cn>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;++i){
        cin>>val[i];
        for(int j=1;j<=cn;++j){
            ++tot;
            o[tot].u=i;
            o[tot].v=j;
            cin>>o[tot].w;
        }
    }
    if(cn==1){
        cout<<0;
        return 0;
    }
    sort(e+1,e+m+1,cmp);
    sort(o+1,o+tot+1,cmp);
    for(vis=0;vis<=(1<<k)-1;++vis){
        solve();
    }
    cout<<ans;
    return 0;
}
