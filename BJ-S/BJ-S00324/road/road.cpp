#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//priority_queue<>q;
struct node{
    ll to,w;
};
struct edge{
    ll fo,net,w;
};
edge q[1000005];
ll fa[10005];
ll n,m,k,ans;
vector<node>p[10005];
bool ch[10005];
inline ll Find(ll x){
    if(fa[x]==x)return x;
    else return fa[x]=Find(fa[x]);
}
inline bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)fa[i]=i;
    if(k==0){
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&q[i].fo,&q[i].net,&q[i].w);
        }
        sort(q+1,q+m+1,cmp);

        ll tot=0;
 //       ch[S]=1;
        for(int i=1;i<=m;i++){
            ll x=q[i].fo;
            ll y=q[i].net;
            if(Find(x)==Find(y))break;
            fa[Find(y)]=Find(x);
            ans+=q[i].w;
        }

        printf("%lld",ans);
        return 0;
    }

    for(int i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        p[u].push_back({v,w});
        p[v].push_back({u,w});
    }

    return 0;
}
