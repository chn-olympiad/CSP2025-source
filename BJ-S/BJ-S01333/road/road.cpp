#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector <pair <int,int>> e[10004];
int a[11][10004],c[11];
int ansmx = 1e18;
priority_queue <pair <int,pair <int,int>>> q;
int fa[10014];
int pic = 1;
inline int find (int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}
signed main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
    }
    for (int i = 1;i <= k;i++) {
        cin >> c[i];
        pic *= c[i];
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for (int t = 0;t < (1 << k);t++) {
        if (pic == 0 && t != ((1 << k) - 1)) {
            continue;
        }
        int ans = 0;
        for (int i = 1;i <= n + k;i++) {
            fa[i] = i;
        }
        for (int i = 1;i <= k;i++) {
            if (t & (1ll << (i - 1))) {
                ans += c[i];
                for (int j = 1;j <= n;j++) {
                    q.push({-a[i][j],{n + i,j}});
                }
            }
        }
        for (int i = 1;i <= n;i++) {
            for (auto at : e[i]) {
                int v = at.first,w = at.second;
                q.push({-w,{i,v}});
            }
        }
        while (!q.empty()) {
            auto au = q.top();
            q.pop();
            int w = -au.first,u = au.second.first,v = au.second.second;
            u = find(u),v = find(v);
            if (u != v) {
                fa[u] = v;
                ans += w;
            }
        }
        ansmx = min(ansmx,ans);
    }
    cout << ansmx << endl;
    return 0;
}
/*
ru ci sheng huo san sh nian
zhi dao da sha beng ta
yun ceng shen chu de hei an na
yan mo xin di de jing guan
*/