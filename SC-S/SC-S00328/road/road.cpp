#include <bits/stdc++.h>
#define i64 long long
#define dbg(x)
// #define dbg(x) cerr << #x << " = " << (x) << "\n"
using namespace std;

i64 n,m,k;
const i64 N = 2e6 + 3;
struct node{
    i64 u,v,w;
} line[N];
vector<node> cli;
i64 st[N];
struct DSU{
    vector<i64> pa,siz;
    DSU(i64 x) : pa(x),siz(x,1) {
        iota(pa.begin(),pa.end(),0);
    }
    i64 find(i64 x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    void clear(){
        iota(pa.begin(),pa.end(),0);
        fill(siz.begin(),siz.end(),1);
    }
    void unite(i64 x,i64 y){
        i64 sx = find(x),sy = find(y);
        if(siz[sx] < siz[sy]) swap(sx,sy);
        pa[sy] = sx;
        siz[sx] += siz[sy];
    }
};
DSU dsu(N);
i64 nans = 0,fans = LLONG_MAX;

i64 cc(i64 x){
    i64 res = 0;
    while(x){
        if(x & 1) res++;
        x >>= 1;
    }
    return res;
}

bool flag = true;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i64 i = 1;i <= m;i++){
        scanf("%lld%lld%lld",&line[i].u,&line[i].v,&line[i].w);
    }
    // sort(line + 1,line + n + m + 1,[](node a,node b){ return a.w < b.w; });
    // pre 1
    for(i64 i = 1;i <= k;i++){
        scanf("%lld",&st[i]);
        if(st[i] != 0) flag = false;
        for(i64 j = 1;j <= n;j++){
            i64 now2;
            scanf("%lld",&now2);
            line[m + i * j] = {i + m,j,now2};
            if(now2 != 0) flag = false;
        }
    }
    if(flag){
        printf("0");
        return 0;
    }
    sort(line + 1,line + k * n + 1,[](node a,node b){ return a.w < b.w; });
    for(i64 i = 0;i < (1 << k);i++){
        i64 cnt = 0;
        nans = 0;
        dsu.clear();
        i64 nw = cc(i);
        i64 ppe = 0;
        for(i64 j = 1;j <= n;j++){
            if(i & (1 << (j - 1))){
                ppe += st[j];
            }
        }
        for(i64 j = 1;j <= k * n && cnt < n + nw;j++){
            node now = line[j];
            if((now.u > m && !(i & (1 << (now.u - m - 1)))) || (now.v > m && !(i & (1 << (now.v - m - 1))))) continue;
            // dbg(1);
            if(dsu.find(now.u) != dsu.find(now.v)){
                dsu.unite(now.u,now.v);
                nans += now.w;
                cnt++;
            }
        }
        dbg(nans);
        fans = min(fans,nans + ppe);
    }
    printf("%lld",fans);
    return 0;
}