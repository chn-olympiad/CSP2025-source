#include <bits/stdc++.h>

typedef long long ll;

const ll maxn=1e4+5;
const ll maxm=1e6+5;
const ll maxk=15;

using std::cin;
using std::cout;

struct edge{
    ll u, v, w;
};

struct node{
    ll v, w;
};

ll deg[maxn];
ll f[maxn];
edge e[maxm], v[maxn*10];
ll cost[maxk];
ll n,m, k, cnt, vcnt, res;
ll sum=0;
std::vector<node> g[maxn+30];


ll find(ll a) {
    if(f[a]==a){
        return a;
    }
    return f[a]=find(f[a]);
}



void solve() {
    std::sort(e+1,e+1+m+k*n+k, [](const edge &a, const edge &b) {
        return a.w < b.w;
    });
    ll tot=1;
    for(ll i=1;i<n;i++) {

        while(find(e[tot].u)==find(e[tot].v) && tot <= cnt) {
            ++tot;
        }
        if(tot > cnt) {
            break;
        }
        ll u=e[tot].u, v=e[tot].v;
        f[find(e[tot].u)]=find(e[tot].v);
        deg[e[tot].u]++;
        deg[e[tot].v]++;
        g[e[tot].v].push_back({e[tot].u, e[tot].w});
        g[e[tot].u].push_back({e[tot].v, e[tot].w});
        res+=e[tot].w;
    }
    return;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);

    for(ll i=1;i<=m;++i) {
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    }
    cnt=m;


    std::iota(f+1,f+1+n+k, 1);


    for(ll i=1;i<=k;++i) {
        scanf("%lld", &cost[i]);
        sum+=cost[i];
        //e[++cnt] = {n+i*k, n+i*k-1, cost[i]};
        ll arr[maxn];
        memset(arr,0,sizeof arr);
        for(ll j=1;j<=n;++j) {
            cin>>arr[j];
        }
        for(ll j=1;j<=n;++j) {
            for(ll k=1;k<=n;++k) {
                if(j==k) {
                    continue;
                }
                e[++cnt] = {j, k, arr[j] + arr[k]};
            }
        }
    }

    //我们现计算在不使用村庄的最小生成树
    solve();
    //我们现在得到了不使用村庄的最小生成树
    //现在考虑使用村庄进行松弛
    //注意村庄本身就是树型结构
    //注意到k特别小


    for(ll i=1;i<=k;++i) {
        //我们枚举每个没有出度的村庄
        if(deg[n+i*2]==1) {
            //这个村庄没有出度，

        }
    }

    printf("%lld\n", res);

	return 0;
}
