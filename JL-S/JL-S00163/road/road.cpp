#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
struct N{
    int u, v, w;
};

vector<N> lis;
vector<int> fa;
ll res = LLONG_MAX;

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool cmp(N a, N b){return a.w < b.w;}

void K(int nn, int p){
    vector<N> b;
    sort(lis.begin(), lis.end(), cmp);
    ll ans = p;
    int cnt = 0;
    for(int i = 0; i < lis.size(); i++){
        int u = find(lis[i].u);
        int v = find(lis[i].v);
        if(u == v) continue;
        fa[v] = u;
        cnt++;
        ans += lis[i].w;
        b.push_back({u, v, lis[i].w});
        if(cnt == nn - 1) break;
    }
    if(res > ans){
        lis = move(b);
        res = ans;
    }
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    fa.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        int uu, vv, ww;
        scanf("%d%d%d",&uu,&vv,&ww);
        lis.push_back({uu, vv, ww});
    }
    K(n, 0);

    int mm = n - 1;
    for(int nn = 1; nn <= k; nn++){
        int c;
        scanf("%d",&c);
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d",&x);
            lis.push_back({i, n + nn, x});
        }
        fa.assign(n + nn + 1, 0);
        for(int i = 1; i <= n + nn; i++) fa[i] = i;
        K(n + nn, c);
    }
    printf("%lld", res);

    return 0;
}
