#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x = 0, f = 1;
    char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
    return x * f;
}
const int N = 1e4 + 5, M = 1e6 + 5;
vector <int> g[N], w[N];
int sk[15][N], c[15], pre[N], n, m, k;
int dis[N][N];
struct line{
    int fr, to, val;
    bool operator <(const line &t) const{
        return val > t.val;
    }
};
priority_queue <line> q;
int find(int x){
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}
void unit(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return ;
    pre[y] = x;
    return ;
}
void solve1(){
    for(int i = 1; i <= n; i++) pre[i] = i;
    int cnt = 0, sum = 0;
    while(!q.empty() && cnt < n - 1){
        line tmp = q.top(); q.pop();
        if(find(tmp.fr) == find(tmp.to)) continue;
        unit(tmp.fr, tmp.to);
        cnt++;
        sum += tmp.val;
    }
    printf("%lld", sum);
    return ;
}
void solve2(){
    memset(dis, 0x3f, sizeof(dis));
    for(int l = 1; l <= k; l++){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int val = sk[l][i] + sk[l][j] + c[l];
                if(dis[i][j] > val){
                    dis[i][j] = val;
                    q.push({i, j, val});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) pre[i] = i;
    int cnt = 0, sum = 0;
    while(!q.empty() && cnt < n - 1){
        line tmp = q.top(); q.pop();
        if(find(tmp.fr) == find(tmp.to)) continue;
        unit(tmp.fr, tmp.to);
        cnt++;
        sum += tmp.val;
    }
    printf("%lld", sum);
    return ;
}
void solve3(){
    solve2();
    return ;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1, u, v, val; i <= m; i++){
        u = read(), v = read(), val = read();
        if(u > v) swap(u, v);
        g[u].push_back(v);
        w[u].push_back(val);
        q.push({u, v, val});
    }
    int flag = 0;
    if(k == 0){
        solve1();
    }else{
        for(int i = 1; i <= k; i++){
            c[i] = read();
            if(c[i] != 0) flag = 1;
            for(int j = 1; j <= n; j++){
                sk[i][j] = read();
            }
        }
        if(!flag) solve2();
        else solve3();
    }
    return 0;
}