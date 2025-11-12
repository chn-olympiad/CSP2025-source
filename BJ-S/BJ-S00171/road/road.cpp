#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10,M = 1e6 + 10;
#define ll long long
int n,m,k,f[N + 10],all,now[11];
ll ans,c[11];
struct Edge {
    int x,y; ll w;
    bool operator < (Edge ed) const { return w < ed.w; }
} E[M];
vector <Edge> v[12];
multiset <pair <ll,int> > st;
void init() {
    for(int i = 1;i <= n + k;i++) f[i] = i;
    return ;
}
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k; all = n;
    for(int i = 1;i <= m;i++)
        cin >> E[i].x >> E[i].y >> E[i].w;
    sort(E + 1,E + m + 1); init();
    for(int i = 1;i <= m;i++) {
        int x = E[i].x,y = E[i].y;
        x = getf(x),y = getf(y);
        if(x == y) continue;
        f[y] = x; ans += E[i].w;
        v[k].push_back(E[i]); all--;
        if(all == 1) break;
    }
    sort(v[k].begin(),v[k].end());
    for(int i = 0;i < k;i++) {
        cin >> c[i];
        for(int j = 1;j <= n;j++) {
            ll w; cin >> w;
            v[i].push_back({n + 1 + i,j,w});
        }
        sort(v[i].begin(),v[i].end());
    }
    for(int S = 0;S < (1 << k);S++) {
        vector <int> use; ll tot = 0;
        st.clear(); int cnt = n;
        for(int i = 0;i < k;i++) {
            if(S & (1 << i)) {
                use.push_back(i);
                tot += c[i]; cnt++;
            }
        }
        use.push_back(k);
        for(int x : use) {
            now[x] = 0;
            st.insert({v[x][0].w,x});
        }
        init();
        while(cnt > 1) {
            auto it = st.begin();
            int x = (*it).second;
            Edge e1 = v[x][now[x]];
            int nx = e1.x,ny = e1.y;
            nx = getf(nx); ny = getf(ny);
            st.erase(it); now[x]++;
            if(now[x] < v[x].size()) st.insert({v[x][now[x]].w,x});
            if(nx == ny) continue;
            tot = tot + e1.w;
            f[ny] = nx; cnt--;
        }
        ans = min(ans,tot);
    }
    cout << ans;
    return 0;
}