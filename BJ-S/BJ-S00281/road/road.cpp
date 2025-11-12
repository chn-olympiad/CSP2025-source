#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 1e4+20, M=1.1e6+20;
pair<int,pii> e[M];
vector<pii> c[N];
vector<int> dk[15];
int ck[15];
int n, m, k;
int fa[N];
int find(int x) {
    if (fa[x]==x) return x;
    else return find(fa[x]);
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n+k; i++) {
        fa[i] = i;
    }
    int tm = m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[i] = {z,{x,y}};
    }
    for (int j = 1; j <= k; j++) {
        cin >> ck[j];
        for (int i = 1; i <= n; i++) {
            int z;
            int x = j+n;
            cin >>z;
            e[++m] = {z,{x, i}};
        }
    }
    sort(e+1,e+m+1);
    int cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt>=n+k) break;
        int x = e[i].se.fi,y=e[i].se.se;
        int w = e[i].fi;
        if (find(x)!=find(y)) {
            merge(x,y);
            if (x>n) {
                dk[x-n].push_back(w);
            }
            ans += w;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
