#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct rd{
    long long u, v, w;
    int js;
    bool operator<(rd y)const{
        return w > y.w;
    }
};
vector<rd> tu;
long long xc[12][10010];
int fa[20010];
int getfa(int x){
    if(x == fa[x]) return x;
    return fa[x] = getfa(fa[x]);
}
int cz[12];
int qzh[12];
vector<rd> cs[12];
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        tu.push_back({u,v,w,0});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin >> xc[i][j];
        }
    }
  
    priority_queue<rd> q;

    for(int i=0;i<m;i++){
        q.push(tu[i]);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            q.push({i + n, j, xc[i][j] + xc[i][0], 0});
        }
    }
    // while(q.size()){
    //     printf("%d %d %d\n", q.top().u, q.top().v, q.top().w);
    //     q.pop();
    // }
    for(int i=0;i<=n+k;i++) fa[i] = i;
    long long sy = 0, ans = 0;
    int zs= n;
    for(;q.size() && sy < zs-1;){
        auto u = q.top();
        q.pop();
        // printf("-----------%lld %lld %lld\n", u.u, u.v, u.w);
        int fx = getfa(u.u);
        int fy = getfa(u.v);
        if(fx != fy){
            if(u.u > n){
                if(cz[u.u - n] == 1){
                    if(u.js == 0) continue;
                    cz[u.u - n] = 2;
                    q.push({u.u, u.v, u.w+qzh[u.u-n], 2});
                    qzh[u.u-n] = u.w+qzh[u.u-n];
                } else if(cz[u.u - n] == 0){
                    // zs++;
                    for(int i=1;i<=n;i++){
                        // if(i == u.v) continue;
                        q.push({u.u, i, xc[u.u-n][i], 1});
                    }
                    cz[u.u-n] = 1;
                    fa[fx] = fy;
                    qzh[u.u-n] = u.w;
                } else if(cz[u.u-n]==2){
                    if(u.js == 0) continue;
                    if(u.js == 1){
                        cs[u.u-n].push_back(u);
                        continue;
                    }
                    fa[fx] = fy;
                    ans += u.w;
                    sy += 2;
                    zs ++;
                    cz[u.u-n]= 3;
                    while(cs[u.u-n].size()){
                        q.push(cs[u.u-n].back());
                        cs[u.u-n].pop_back();
                    }
                } else {
                    if(u.js == 0) continue;
                    fa[fx] = fy;
                    sy ++;
                    ans += u.w;
                }
                
            } else {
                fa[fx] = fy;
                sy ++;
                ans += u.w;
            }
        }
    }
        
    printf("%lld", ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/