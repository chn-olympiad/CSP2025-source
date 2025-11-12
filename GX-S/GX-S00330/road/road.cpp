#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long

const int N = 1e4 + 20;
const int M = 20;
struct node {
    int v, w;
};
struct roas {
    int u, v, w, sign;
    bool operator>(const roas other) const{
        return w > other.w;
    }
    bool operator<(const roas other) const{
        return w < other.w;
    }
};
//vector<node> adj[N];
//priority_queue<roas, vector<roas>, greater<roas> > pq;
vector<roas> roa;
int ufset[N] = {};
int vall[M][N] = {};
bool sl[N] = {};
int n, m, k;
ll ans = 0;

int Fin(int x) {
    if (ufset[x] == x) {
        return x;
    }
    return ufset[x] =  Fin(ufset[x]);
}

void Uni(int a, int b) {
    ufset[Fin(a)] = b;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    for (int i=1;i<N;i++) {
        ufset[i] = i;
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        //adj[u].push_back({v, w});
        //pq.push({u, v, w});
        roa.push_back({u, v, w, 0});
    }
    bool flag1 = 1;
    for (int j=1;j<=k;j++) {
        for (int p=0;p<=n;p++) {
            cin >> vall[j][p];
            if (p==0 && vall[j][p]!=0) flag1 = 0;
        }
    }
    if (flag1) {
        // A
        for (int j=1;j<=k;j++) {
            for (int p=1;p<=n;p++) {
                roa.push_back({j+n, p, vall[j][p]});
            }
        }
        sort(roa.begin(), roa.end());
        for (auto ed : roa) {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if (Fin(u) == Fin(v)) continue;
            Uni(u, v);
            ans += w;
        }
        cout << ans;
    }
    else {
        //!A
        for (int j=1;j<=k;j++) {
            int xiao = 0x3f3f3f3f;
            int q = 0;
            for (int p=1;p<=n;p++) {
                if (xiao > vall[j][p]) {
                    xiao = vall[j][p];
                    q = p;
                }
            }
            roa.push_back({j+n, q, xiao+vall[j][0], j+n});
        }
        sort(roa.begin(), roa.end());
        int cnt = 0;
        int leng = roa.size();
        for (int i=0;i<leng;i++) {
            roas ed = roa[i];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            int sign = ed.sign;
            if (Fin(u) == Fin(v) || cnt >= n-1) continue;
            Uni(u, v);
            if (sign) {//vall
                if (sl[u]) {
                    ans += w-vall[u-n][0];
                    cnt++;
                }
                else {
                    ans += w;
                    sl[u] = 1;
                        for (int p=1;p<=n;p++) {
                            if (p != v) roa.push_back({u, p, vall[u-n][p], u});
                        }
                    sort(roa.begin()+i, roa.end());
                    leng = roa.size();
                }
            }
            else {
                ans += w;
                cnt++;
            }
        }
        cout << ans;
    }

    return 0;
}
