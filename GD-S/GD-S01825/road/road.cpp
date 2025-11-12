#include <bits/stdc++.h>
using ll = long long;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 15;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
ll ans,c[N],a[K][M],minp[K];
struct mgs{
    int fa[N];
    void init(){for(int i = 1;i <= n;i++) fa[i] = i;}
    int find(int x){return fa[x] == x ? fa[x] : find(fa[x]);}
    void merge(int x,int y){fa[find(x)] = fa[find(y)];}
}MGS;
struct edge{
    int u,v;
    ll w;
    bool operator < (const edge &rhs) const {return w < rhs.w;}
}e[M];

void solve1(){
    std::sort(e + 1,e + m + 1);
    for(int cn = n,i = 1;i <= m && cn > 1;i++){
        auto [u,v,w] = e[i];
        if(MGS.find(u) != MGS.find(v)){
            MGS.merge(u,v);
            ans += w;
            cn--;
        }
    }
    std::cout << ans << '\n';
}
void solve2(){
    std::vector<edge> used;
    std::sort(e + 1,e + m + 1);
    for(int cn = n,i = 1;i <= m && cn > 1;i++){
        auto [u,v,w] = e[i];
        if(MGS.find(u) != MGS.find(v)){
            MGS.merge(u,v);
            used.push_back(e[i]);
            ans += w;
            cn--;
        }
    }
    ll nans = 0;
    for(int use = (1 << k) - 1;use;use--,nans = 0){
        std::vector<edge> ne;
        for(auto i : used)
            ne.push_back(i);
        for(int bt = 0;bt < k;bt++)
            if(use & (1 << bt)){
                int st = minp[bt + 1];
                nans += c[bt + 1] + a[bt + 1][st];
                for(int i = 1;i <= n;i++) if(i != minp[bt + 1])
                    ne.push_back({st,i,a[bt + 1][i]});
            }
        std::sort(ne.begin(),ne.end());
        int cn = n;
        MGS.init();
        for(auto i = ne.begin();i != ne.end() && cn > 1;i++){
            auto [u,v,w] = *i;
            if(MGS.find(u) != MGS.find(v)){
                MGS.merge(u,v);
                nans += w;
                cn--;
            }
        }
        ans = std::min(ans,nans);
    }
    std::cout << ans << '\n';
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::cin.tie(0) -> sync_with_stdio(0);
    std::memset(minp,0x3f,sizeof(minp));

    std::cin >> n >> m >> k;
    MGS.init();
    for(int i = 1;i <= m;i++)
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    bool flag = 1;
    for(int j = 1;j <= k;j++){
        std::cin >> c[j];
        if(c[j] != 0) flag = 0;
        for(int i = 1;i <= n;i++){
            std::cin >> a[j][i];
            if(i == 1) minp[j] = 1;
            else if(a[j][i] < a[j][minp[j]]) minp[j] = i;
        }
    }

    if(k == 0)
        solve1();
    else
        solve2();
    return 0;
}