#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100005];
int rnk[100005];
struct Edge{
    int u;int v;ll w;
};
Edge edge[2000005];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int find(int a){
    if(f[a]!=a)f[a]=find(f[a]);
    return f[a];
}
bool build(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return false;
    if(rnk[a]>rnk[b])f[b]=a;
    else{
        f[a]=b;
        if(rnk[a]==rnk[b])++rnk[b];
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,cnt=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        ++cnt;
        cin>>edge[cnt].u>>edge[cnt].v>>edge[cnt].w;
    }
    for(int i=1;i<=k;++i){
        ll x;
        cin>>x;
        ll ne[100005];
        for(int j=1;j<=n;++j){
            cin>>ne[j];
        }
        for(int u=2;u<=n;++u){
            for(int v=1;v<u;++v){
                ++cnt;
                edge[cnt].u=u;
                edge[cnt].v=v;
                edge[cnt].w=x+ne[u]+ne[v];
            }
        }
    }
    for(int i=1;i<=n;++i){
        rnk[i]=0;
        f[i]=i;
    }
    sort(edge+1,edge+1+cnt,cmp);
    ll ans=0;
    int sum=1;
    for(int i=1;i<=cnt;++i){
        if(build(edge[i].u,edge[i].v)){
            ++sum;
            ans+=edge[i].w;
        }
        if(sum==n)break;
    }
    cout<<ans;
    return 0;
}
