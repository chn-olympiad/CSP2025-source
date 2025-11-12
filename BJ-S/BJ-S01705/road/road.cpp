#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int MR = 1e6;
const int NR = 1e4;
const int KR = 10;
struct Edge{
    int u, v, w;
}e[MR + 10];
int a[KR + 10][NR + 10];
vector<PII> mp[NR + 10];
struct Unf{
    int fa[NR + 10];
    void init(int x){
        for(int i = 1;i <= x;i++){
            fa[i] = i;
        }
    }
    int Find(int x){
        if(fa[x] == x) return x;
        return fa[x] = Find(fa[x]);
    }
    void Union(int x, int y){
        int fx = Find(x);
        int fy = Find(y);
        fa[fx] = fy;
        return ;
    }
}unf;
bool cmp(Edge x, Edge y){
    return x.w < y.w;
}
vector<Edge> vec;
vector<Edge> ev;
LL kruskal(int n){
    unf.init(n);
    sort(ev.begin(), ev.end(), cmp);
    int cnt = 0;
    LL sum = 0;
    for(auto i : ev){
        int u = i.u;
        int v = i.v;
        int fu = unf.Find(u);
        int fv = unf.Find(v);
        if(fu != fv){
            unf.Union(fu, fv);
            cnt++;
            sum += i.w;
        }
        if(cnt == n - 1) break;
    }
    return sum;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    for(int i = 1;i <= k;i++){
        for(int j = 0;j <= n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    vec.clear();
    unf.init(n);
    sort(e + 1, e + 1 + m, cmp);
    int cnt = 0;
    for(int i = 1;i <= m;i++){
        int u = e[i].u;
        int v = e[i].v;
        int fu = unf.Find(u);
        int fv = unf.Find(v);
        if(fu != fv){
            unf.Union(fu, fv);
            cnt++;
            vec.emplace_back(e[i]);
        }
        if(cnt == n - 1) break;
    }
    LL Min = LLONG_MAX;
    for(int S = 0;S < (1 << k);S++){
        LL sum = 0;
        ev = vec;
        int nn = n;
        for(int i = 1;i <= k;i++){
            if(S & (1 << (i - 1))){
                sum += a[i][0];
                nn++;
                for(int j = 1;j <= n;j++){
                    ev.emplace_back(Edge{nn, j, a[i][j]});
                }
            }
        }
        Min = min(Min, sum + kruskal(nn));
    }
    printf("%lld\n", Min);
    return 0;
}
/*
cd ~/road && g++ road.cpp -O2 -o road && ./road
*/