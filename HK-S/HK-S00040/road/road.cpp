#include <bits/stdc++.h>
using namespace std;

#define N 10010
#define K 11
#define int long long

vector<int> f[N];
vector<int> cs, cv;

int cur = 0;

struct pt{
    int u, v, c, tt;
    bool check(){
        return tt < 0 || (cur & 1 << tt);
    }
    const bool operator<(const pt other) const {
        return c < other.c;
    }
};

int fa[N];
int get(int x){
    if(fa[x] == x) return fa[x];
    return fa[x] = get(fa[x]);
}

int solve(int n, vector<pt> P){
    for(int i = 0; i < n; i++)
        fa[i] = i;
    int res = 0;
    int cnt = 0;
    for(pt p: P){
        if(p.check() && get(p.u) != get(p.v)){
            fa[get(p.v)] = get(p.u);
            cnt++;
            res += p.c;
            cs[p.u]++;
            cs[p.v]++;
            cv[p.u] += p.c;
            cv[p.v] += p.c;
            if(cnt == n - 1) return res;
        }
    }
    return res;
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pt> P;
    vector<int> c(k);
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        P.push_back({--u, --v, c, -1});
    }
    int ccc = 0;
    for(int i = 0; i < k; i++){
        cin >> c[i];
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        int si = -1;
        if(!c[i])for(int j = 0; j < n; j++) if(!a[j]) si = j;
        if(!c[i] && si >= 0) ccc += 1 << i;
        for(int j = 0; j < n; j++){
            if(!c[i] && si >= 0) { if(j != si) P.push_back({j, si, a[j], -1});}
            else P.push_back({i + n, j, a[j], i});
        }
    }

    sort(P.begin(), P.end());
    int ans = 1ll << 60;
    for(cur = 0; cur < 1 << k; cur++){
        int cnt = 0;
        bool f = 0;
        for(int i = 0; i < k; i++)
            if(ccc >> i & 1 && !(cur >> i & 1)) f = 1;
        if(f) continue;
        for(int i = 0; i < k; i++) cnt += cur >> i & 1 - ccc >> i & 1;
        cs.assign(n + k, 0);
        cv.assign(n + k, 0);
        int res = solve(cnt + n, P);
        for(int i = 0; i < k; i++){
            if(cur & 1 << i){
                res += c[i];
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
