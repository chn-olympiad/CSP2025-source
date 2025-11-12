#include <bits/stdc++.h>
struct edge {
    int from;
    int to;
    int dis;
};
bool operator<(edge e1,edge e2) {
    return e1.dis > e2.dis;
}
std::priority_queue<edge> q;
int root[100010];
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,w,ans = 0;
    std::cin>>n>>m>>k;
    for(int i = 1;i <=n;i++) {
        root[i] = i;
    }
    for(int i = 0;i < m;i++) {
        std::cin>>u>>v>>w;
        q.push({u,v,w});
    }
    int count = n-1;
    while(count--) {
        while(root[q.top().from] == root[q.top().to]) {
            q.pop();
        }
        for(int i = 1;i <= n;i++) {
            if(i != q.top().from && root[i] == root[q.top().from]) {
                root[i] = root[q.top().to];
            }
        }
        root[q.top().from] = root[q.top().to];
        ans += q.top().dis;
        q.pop();
    }
    std::cout<<ans;
    return 0;
}
