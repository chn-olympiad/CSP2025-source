#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e4 + 5;
const ll maxm = 1e6 + 5;
struct node {
    ll u,v,w;
};
ll n,m,k,cnt,sot,res;
ll fa[maxn+10];
node age[maxm];
ll s[15]; //build's money
ll money[15][maxn]; //add's money
ll c[15][2];
bool vis[15]; //build yes or no
ll Find(ll x) {
    return fa[x]==x? fa[x]:fa[x]=Find(fa[x]);
}
bool cmp(node x,node y) {
    return x.w<y.w;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n+k;++i) fa[i]=i;
    for(ll i=1;i<=m;++i) scanf("%lld%lld%lld",&age[i].u,&age[i].v,&age[i].w);
    for(ll i=1;i<=k;++i) {
        scanf("%lld",&s[i]);
        for(ll j=1;j<=n;++j) scanf("%lld",&money[i][j]);
    }
    sort(age+1,age+m+1,cmp);
    for(ll i=1;i<=m;++i) {
        ll u=age[i].u;
        ll v=age[i].v;
        ll w=age[i].w;
        if(Find(u)==Find(v)) continue;
        res+=w;
        fa[u]=Find(v);
        ++cnt;
        if(cnt==n-1) break;
    } printf("%lld\n",res);
    return 0;
}
