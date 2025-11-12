#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n, m, k;
int val[11];
int dis[11][N];
int ansi = (ll)1e18;

struct node {
    int x, y, w;
}aedge[M << 1], nedge[M << 1];

bool vis[M << 1];
bool used[11], nused[11];

bool cmp(node x, node y) {
    return x.w < y.w;
}

int fa[N + 50], cnt;
int nn, mm, fee;
int in[N + 50];

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void kruskal(int now) {
    int tot = 0, sum = 0;
    cnt = 0;
    for(int i = 1; i <= mm; ++i)
        nedge[++tot] = aedge[i];

    if(now) {
        for(int i = 1; i <= n; ++i)
            nedge[++tot] = node{now + n, i, dis[now][i]};
    }

    sort(nedge + 1, nedge + tot + 1, cmp);
    for(int i = 1; i <= n + now; ++i) {
        fa[i] = i;
        in[i] = 0;
    }
    for(int i = 1; i <= tot; ++i)
        vis[i] = false;
    for(int i = 1; i <= tot; ++i) {
        int x = nedge[i].x, y = nedge[i].y, w = nedge[i].w;
        int fx = find(x), fy = find(y);
        if(fx == fy) continue;
        vis[i] = true;
        fa[fx] = fy;
        sum += w;
        ++cnt;
        ++in[x], ++in[y];
        if(cnt == nn) break;
    }
    if(!now) {
        mm = 0;
        for(int i = 1; i <= tot; ++i)
            if(vis[i]) 
                aedge[++mm] = nedge[i];
        ansi = sum;
        return;
    }
    if(in[now + n] == 1) return;
    if(now == 3) {
        for(int i = 1; i <= tot; ++i) {
            if(!vis[i]) continue;
            int x = nedge[i].x, y = nedge[i].y;
            if(x == 2 + n) cout << y << " ";
            if(y == 2 + n) cout << x << " ";
        }
    }

    // cerr << now << ": " << fee << " " << sum << "\n";
    nused[now] = true;
    fee += val[now];
    for(int i = 1; i < now; ++i) {
        // cout << fa[i + n] << " ";
        nused[i] = false;
        if(!used[i]) continue;
        nused[i] = true;
        if(in[i + n] == 1) {
            // cerr << "Run here";
            nused[i] = false;
            fee -= val[i];
        }
    }
    
    sum = 0;
    for(int i = 1; i <= tot; ++i) {
        if(vis[i]) {
            vis[i] = false;
            if(nedge[i].x > n && nused[nedge[i].x - n] == false) continue;
            if(nedge[i].y > n && nused[nedge[i].y - n] == false) continue;
            sum += nedge[i].w;
            vis[i] = true;
        }
    }

    if(sum + fee < ansi) {
        mm = 0;
        for(int i = 1; i <= tot; ++i)
            if(vis[i]) 
                aedge[++mm] = nedge[i];
        for(int i = 1; i <= now; ++i)
            used[i] = nused[i];
        ++nn;
        ansi = sum + fee;
    }
    else {
        fee = 0;
        for(int i = 1; i <= now; ++i)
            if(used[i])
                fee += val[i];
    }
}

signed main() {
    freopen("road.in", "r", stdin);
    // freopen("road.out","w", stdout);
    ios :: sync_with_stdio(false);
    cin >> n >> m >> k;
    nn = n, mm = m;
    for(int i = 1; i <= m; ++i)
        cin >> aedge[i].x >> aedge[i].y >> aedge[i].w;
    for(int i = 1; i <= k; ++i) {
        cin >> val[i];
        for(int j = 1; j <= n; ++j)
            cin >> dis[i][j];
    }
    for(int i = 0; i <= k; ++i) {
        kruskal(i);
        // cerr << ansi << " ";
    }
    // for(int i = 1; i <= k; ++i)
        // if(used[i])
            // cout << i << " ";
    // for(int i = 1; i <= mm; ++i)
        // cout << aedge[i].x << " " << aedge[i].y << " " << aedge[i].w << "\n";
    cout << ansi;
    return 0;
}
/*
不想想了，随便打打。
我想写小作文。
*/