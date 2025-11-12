//666 no egg can't speak ch
//there is any distinguish in "chengshi" and "xiangzheng"???
//go **** city and village
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+10;
const int M = 1e6+10;
ll fa[N<<2];
ll n,m,k,ans = 0;
struct node{
    ll u,v,w,next;
}edge[M<<2];
ll head[N<<2];
ll cnt = 0,tot = 1;
ll chose = 0;
bool ce = true;
void addedge(ll u,ll v,ll w){
    edge[++cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    //edge[cnt].kind = k;
    head[u] = cnt;
}
bool cmp(node x,node y){
    return x.w<y.w;
}

struct urbanise{
    ll cost,w[N];
    bool vis = false;
}city[15];

ll find(ll u){
    if(u == fa[u]) return fa[u];
    return fa[u] = find(fa[fa[u]]);
}
void merge(ll x,ll y){
    fa[x] = find(fa[y]);
}
void init(){
    for(int i = 0; i < N; ++i) fa[i] = i;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    init();
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i = 1,u,v,w; i <= m; ++i){
        scanf("%lld%lld%lld",&u,&v,&w);
        addedge(u,v,w);
    }
    sort(edge+1,edge+1+m,cmp);
    for(ll i = 1; i <= k; ++i){
        scanf("%lld",&city[i].cost);
        city[i].vis = false;
        if(city[i].cost != 0) ce = false;
        for(int j = 1; j <= n; ++j){
            scanf("%lld",&city[i].w[j]);
        }
    }
    if(k == 0){
        for(int i = 1; i <= m; ++i){
            int u = edge[i].u;
            int v = edge[i].v;
            if(fa[u] == fa[v]) continue;
            ans += edge[i].w;
            merge(u,v);
            chose++;
            if(chose == n-1) break;
        }
    }
    else if(k != 0 && ce == false){
        for(ll i = 1; i <= m; ++i){
            ll u = edge[i].u;
            ll v = edge[i].v;
            if(fa[u] == fa[v]) continue;
            ll res = 0x3f3f3f3f;
            for(int j = 1; j <= tot - 1; ++j){
                res = min(city[j].w[u] + city[j].w[v],res);
            }
            //printf("section 1: %lld\nsection 2: %lld\n",res,city[tot].w[u] + city[tot].w[v] + city[tot].cost);
            if(edge[i].w > res){
                ans += res;
                merge(u,v);
                //printf("build %lld %lld  chose urban   then res is %lld\n",u,v,res);
                break;
            }

            if(edge[i].w > city[tot].w[u] + city[tot].w[v] + city[tot].cost){
                ans += city[tot].w[u] + city[tot].w[v] + city[tot].cost;
                tot++;
                merge(u,v);
                //printf("build %lld %lld  chose new urban  then cost is %lld\n",u,v,city[tot].w[u] + city[tot].w[v] + city[tot].cost);
                break;
            }
            //printf("build %lld %lld  chose old  the older is %lld\n",u,v,edge[i].w);
            ans += edge[i].w;
            merge(u,v);
            chose++;
            if(chose == n-1) break;
        }
    }

        else if(k != 0 && ce == true){


            for(ll i = 1; i <= k; ++i){
                for(ll j = 1; j <= n; ++j){
                    addedge(n+i,j,city[i].w[j]);
                    m++;
                }
            }
            sort(edge+1,edge+1+m,cmp);
            for(ll i = 1; i <= m; ++i){

                int u = edge[i].u;
                int v = edge[i].v;
                if(fa[u] == fa[v]) continue;
                //printf("now decide edge %lld: from %lld to %lld, value is %lld\n",i,u,v,edge[i].w);
                ans += edge[i].w;
                if(u > n){
                    if(city[u-n].vis == false){
                        n++;
                        city[u-n].vis = true;
                    }
                }
                merge(u,v);
                chose ++;
                //printf("added %lld edge, now value: %lld\n\n",chose,ans);
                if(chose == n-1) break;
            }
        }

    printf("%lld\n",ans);
    return 0;
}
