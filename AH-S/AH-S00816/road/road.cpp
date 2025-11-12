#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[20005],fa[20005],ans=1e18,f[20005];
struct edge{
    long long u,v,w;
}e[2000005];
int fd(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=fd(fa[x]);
}
void Kruskal(long long num,long long sum){
    long long tot=n+num-1;
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    long long cnt=0,ret=0;
    for(int i=1;i<=m;i++){
        if(cnt==tot){
            break;
        }
        long long x=e[i].u,y=e[i].v,z=e[i].w;
        if(!f[x]){
            continue;
        }
        long long fax=fd(x),fay=fd(y);
        if(fax!=fay){
            fa[fax]=fay;
            cnt++;
            ret+=z;
        }
    }
    ans=min(ans,ret+sum);
}
void dfs(long long x,long long cnt,long long sum){
    if(x>n+k){
        Kruskal(cnt,sum);
        return;
    }
    f[x]=0;
    dfs(x+1,cnt,sum);
    f[x]=1;
    dfs(x+1,cnt+1,sum+a[x]);
}
bool cmp(edge p,edge q){
    return p.w<q.w;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        f[i]=1;
    }
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>a[i+n];
        for(int j=1;j<=n;j++){
            m++;
            cin>>e[m].w;
            e[m].u=i+n;
            e[m].v=j;
        }
    }
    sort(e+1,e+1+m,cmp);
    dfs(n+1,0,0);
    cout<<ans;
    return 0;
}
