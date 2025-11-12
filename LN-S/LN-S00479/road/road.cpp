
#include <bits/stdc++.h>
#define MAXM (1000100)
#define MAXN (10010)
using namespace std;
int N, M, K;
long long ans;
int num;
int par[MAXN];
struct Edge {
    int u, v, w;
} E[MAXM];
bool Cmp(Edge a, Edge b) {
    return a.w < b.w;
}
int Find(int x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> N >> M >> K;
    for(int i=1;i<=M;i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E+1, E+M+1, Cmp);
    for(int i=1;i<=N;i++) {
        par[i] = i;
    }
    for(int i=1;i<=M;i++) {
        if(num >= N-1) break;
        int u = E[i].u, v = E[i].v;
        int pu = Find(u), pv = Find(v);
        if(pu == pv) continue;
        par[pu] = pv;
        num ++;
        ans += E[i].w;
    }
    cout << ans;
    return 0;
}
