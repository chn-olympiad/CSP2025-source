#include <bits/stdc++.h>
using namespace std;

int n, m, k, p, tot;
int dis[10010], a[11], to[11][10010];
bool vis[10010];
int fa[10010];

struct edg{
    int node, dist, node2;
};
struct cmp{
    bool operator()(edg x, edg y){
        return x.dist > y.dist;
    }
};
priority_queue<edg, vector<edg>, cmp> pq;

int fnd(int x){
    return fa[x] = (x == fa[x] ? x : fnd(fa[x]));
}
int unionn(int x, int y){
    int tx = fnd(x), ty = fnd(y);
    if(tx != ty){
        fa[tx] = ty;
        return 1;
    }
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        pq.push({t1, t3, t2});
    }
    
    for(int i = 1; i <= n; i++) fa[i] = i;

    while(!pq.empty() && p != n - 1){
        int t1, t2, t3;
        t1 = pq.top().node;
        t2 = pq.top().node2;
        t3 = pq.top().dist;
        if(unionn(t1, t2)) p++, tot += t3;
        pq.pop();
    }
    
    cout << tot;
}