#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define int long long

using namespace std;

const int N = 1e4 + 110;
const int M = 1e6 + 10;
const int T = 1050;

int n, m, k;
int f[N], lg[N];
int lowbit (int x) {
    return x & -x;
}

int find (int x) {
    if(f[x] != x) f[x] = find (f[x]);
    return f[x];
}
struct node {
    int to, w;
};
struct E {
    int a, b, c;
}e[M];

bool operator > (E a, E b) {
    return a.c > b.c;
}

bool operator < (E a, E b) {
    return a.c < b.c;
}
vector <node> adj[N];
vector <E> vc[N];

bool cmp2 (node a, node b) {
    return a.w < b.w;
}

int cost[N];

int dp[T];
E tmp[15][N];

int sol (int x, int s) {
    //cout << x << " " << s << endl;
    int nw = s + (1 << (x - n - 1));
    //cout << nw << endl;
    int res = 0;
    int pos = 1;
    for (int i = 1; i <= n; i ++ ) f[i] = i;
    int cnt = 0;
    for (int i = 0; i < vc[s].size(); i ++ ) {
        while (pos <= n && tmp[x - n][pos].c < vc[s][i].c) {
            int a = tmp[x - n][pos].a, b = tmp[x - n][pos].b, c = tmp[x - n][pos].c;
            pos ++ ;
            int fa = find (a), fb = find (b);
            //cout << a << " " << b << " " << c << endl;
            if (fa == fb) continue;
            cnt ++ ;
            f[fa] = fb;
            res += c;
            vc[nw].push_back ({a, b, c});
        }
        if (cnt == n - 1) break;
        int a = vc[s][i].a, b = vc[s][i].b, c = vc[s][i].c;
        int fa = find (a), fb = find (b);
        if (fa == fb) continue;
      //  cout << a << " " << b << " " << c << endl;
        f[fa] = fb;
        res += c;
        cnt ++ ;
        vc[nw].push_back ({a, b, c});
        if (cnt == n - 1) break;
        //cout << cnt << endl;
    }
    //cout << "  " << res << endl;
    return res;
}

void sol2 (int x) {
    priority_queue <E, vector <E>, greater <E> > q;
    q.push({0, 1, adj[x + n][0].w + adj[x + n][1].w});
    int pos = 0;
    while (!q.empty () && pos < n) {
        E k = q.top ();
        int idx1 = k.a, idx2 = k.b;
        //cout << idx1 << " " << idx2 << endl;
        q.pop();
        tmp[x][++ pos] = {adj[x + n][idx1].to, adj[x + n][idx2].to, adj[x + n][idx1].w + adj[x + n][idx2].w};
        if (idx2 + 1 < n) q.push({idx1, idx2 + 1, adj[x + n][idx1].w + adj[x + n][idx2 + 1].w});
        if (idx2 > idx1 +1) q.push({idx1 + 1, idx2, adj[x + n][idx1 +1].w + adj[x + n][idx2].w});
      //  cout << "   " << adj[x + n][idx1].w + adj[x + n][idx2].w << endl;
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);

    cin >> n >> m >> k;
    lg[1] = 1;
    for (int i = 1; i <= k; i ++ ) {
        lg[(1 << i)] = i + 1;
    }
    for (int i = 1; i <= m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back ({b, c});
        adj[b].push_back ({a, c});
        e[i] = {a, b, c};
    }
    sort (e + 1, e + m + 1);
    for (int i = 1; i <= n; i ++ ) {
        f[i] = i;
    }

    int ans = 0;
    for (int i = 1;i <= m;i ++ ) {
        int a = e[i].a, b = e[i].b, c = e[i].c;
        int fa = find (a), fb = find (b);
        if(fa == fb) continue;
        ans += c;
        f[fa] = fb;
        vc[0].push_back ({a, b, c});
    }
    //cout << ans << endl;

    for (int i = 1; i <= k; i ++ ) {
        cin >> cost[i];
        for(int j = 1; j <= n; j ++ ) {
            int val; cin >> val;
            //edge [n + i][j] = val;
            adj[n + i].push_back ({j, val});
        }
        sort (adj[n + i].begin (), adj[n + i].end (), cmp2);
      //  for (int j = 0; j < adj[n + i].size(); j ++ ) {
       //     cout << n + i << " " << adj[n + i][j].to << " " << adj[n + i][j].w << endl;
       // }

        sol2 (i);
    }

    dp[0] = 0;
    for (int i = 1; i <= (1 << k) - 1; i ++ ) {
           // cout << lowbit(i) << endl;
        dp[i] = dp[i ^ lowbit(i)] + cost [lg[lowbit(i)]];
        ans = min (ans, dp[i] + sol (n + lg[lowbit (i)], i ^ lowbit(i)));
    }

    cout << ans << endl;
    return 0;
}
