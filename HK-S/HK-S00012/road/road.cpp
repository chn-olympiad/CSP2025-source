#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
#define int long long
#define pii pair<int, int>
#define x first
#define y second
int n, m, k, u[N], w[N], v[N], f[N], ans = 1e10;
vector<pii> g[N];
vector<int> cost[N];
pii c[N];
vector<int> ind;
int findf(int x){
    if (f[x] == x) return x;
    else return f[x] = findf(f[x]);
}
void combine(int a, int b){
    int x = findf(a), y = findf(b);
    if (x != y) f[x] = y;
}
bool cmp(pair<int, pii> a, pair<int, pii> b) {
    return a.x < b.x;
}
void sol(int x) {
    if (x == k + 1) {
        for (int i = 1; i <= n + n; i++) f[i] = i;
        vector<pair<int, pii>> c;
        int cnt = 0;
        for (int i = 1; i <= m; i++) c.push_back({w[i], {u[i], v[i]}});
        for (int i = 0; i < ind.size();i++){
            cnt += cost[ind[i]][0];
            for (int j = 1; j < cost[ind[i]].size(); j++) {
                c.push_back({cost[ind[i]][j], {j, ind[i] + n}});
            }
        }
        sort(c.begin(), c.end(), cmp);
        for (int i = 0;i < c.size(); i++) {

            int a = c[i].y.x, b = c[i].y.y;
        }
        for (int i = 0;i < c.size(); i++) {
            int a = c[i].y.x, b = c[i].y.y;
            if (findf(a) != findf(b)) {
                cnt += c[i].x; combine(a, b);
            }
        }
        ans = min(ans, cnt);
        return;
    } else {

        ind.push_back(x);
        sol(x + 1);
        ind.pop_back();
        sol(x + 1);
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) f[i] = i;
    int mn = 1e10;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        mn = min(mn, w[i]);
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], w[i]});
        c[i] = {w[i], i};
    }
    for (int i = 1; i <= k; i++) {
        int tmp;
        cin >> tmp; cost[i].push_back(tmp);
        for (int j = 1; j <= n; j++) {
            cin >> tmp; cost[i].push_back(tmp);
        }
    }
    if (k == 0) {
        sort(c + 1,c+1+m);
        for (int i = 1 ;i <= m; i++) {
            int a = u[c[i].y], b = v[c[i].y];
            if (findf(a) != findf(b)) {
                ans += c[i].x;
                combine(a, b);
            }
        }
        cout << ans << "\n";
        return 0;
    }
    sol(1);
    cout << ans << "\n";
    fclose(stdin); fclose(stdout);
}
