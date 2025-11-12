#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10;

ll n, m, k, fa[N], ans, tot;

struct f1{
    ll from, to, w;
}ed[N];

void add(ll a, ll b, ll c){
    tot++;
    ed[tot].to = b;
    ed[tot].from = a;
    ed[tot].w = c;
    return;
}

bool cmp(f1 a1, f1 b1){return a1.w<b1.w;}

ll find1(ll x){
    if (x==fa[x]) return x;
    fa[x] = find1(fa[x]);
    return fa[x];
}

void work(){
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(ed+1,ed+m+1,cmp);
    for (int i = 1; i <= m; i++){
        ll fx = find1(ed[i].from);
        ll fy = find1(ed[i].to);
        if (fx==fy) continue;
        fa[fx] = fy;
        ans+=ed[i].w;
    }
    return;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        ll x, y, z;
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y,z);
    }
    if (!k){
        work();
        cout << ans;
    }
    else cout << 0;
    return 0;
}
