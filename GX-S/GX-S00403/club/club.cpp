#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;

int n, a[N][3], b[N][3], c[N][3], ai, bi, ci, g[N];
long long ans;
bool cmpa(int u, int v){
    return min(a[u][0] - a[u][1], a[u][0] - a[u][2])
        > min(a[v][0] - a[v][1], a[v][0] - a[v][2]);
}
bool cmpb(int u, int v){
    return min(b[u][1] - b[u][0], b[u][1] - b[u][2])
        > min(b[v][1] - b[v][0], b[v][1] - b[v][2]);
}
bool cmpc(int u, int v){
    return min(c[u][2] - c[u][1], c[u][2] - c[u][0])
        > min(c[v][2] - c[v][1], c[v][2] - c[v][0]);
}
void slove(){
    cin >> n;
    for (int i = 1, u, v, w; i <= n; i++){
        cin >> u >> v >> w;
        if (u >= v && u >= w){
            a[++ai][0] = u;
            a[ai][1] = v;
            a[ai][2] = w;
            ans += u;
        }
        else if (v >= u && v >= w){
            b[++bi][0] = u;
            b[bi][1] = v;
            b[bi][2] = w;
            ans += v;
        }
        else{
            c[++ci][0] = u;
            c[ci][1] = v;
            c[ci][2] = w;
            ans += w;
        }
    }
    if (ai < (n >> 1) && bi < (n >> 1) && ci < (n >> 1)){
        cout << ans << '\n';
        return ;
    }
    if (ai > bi & ai >ci){
        for (int i = 1; i <= ai; i++)
            g[i] = i;
        sort(g + 1, g + ai + 1, cmpa);
        for (; ai > (n >> 1); ai--)
            ans -= min(a[g[ai]][0] - a[g[ai]][1], a[g[ai]][0] - a[g[ai]][2]);
        cout << ans << '\n';
        return ;
    }
    if (bi > ai & bi >ci){
        for (int i = 1; i <= bi; i++)
            g[i] = i;
        sort(g + 1, g + bi + 1, cmpb);
        for (; bi > (n >> 1); bi--)
            ans -= min(b[g[bi]][1] - b[g[bi]][0], b[g[bi]][1] - b[g[bi]][2]);
        cout << ans << '\n';
        return ;
    }
    for (int i = 1; i <= ci; i++)
        g[i] = i;
    sort(g + 1, g + ci + 1, cmpc);
    for (; ci > (n >> 1); ci--)
        ans -= min(c[g[ci]][2] - c[g[ci]][1], c[g[ci]][2] - c[g[ci]][0]);
    cout << ans << '\n';
}
void init_() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    memset(g, 0, sizeof g);
    ai = bi = ci = 0;
    ans = 0;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        init_();
        slove();
    }
    return 0;
}
