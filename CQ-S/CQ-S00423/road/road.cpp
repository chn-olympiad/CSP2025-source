#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace YYY{
    const int N = 1e4 + 10, M = 2e6 + 10, P = 12, INF = 0x3f3f3f3f3f3f3f3f;
    int n, m, K;
    int a[P][N], val[N];
    struct Edge{int x, y, z, op; }edge[M], edge2[M]; int idx_edge2;
    int p[N];
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    bool cmp(Edge a, Edge b){return a.z < b.z; }
    signed main(){
        n = read(), m = read(), K = read();
        for(int i = 1; i <= n; i ++ ) p[i] = i;
        int x, y, z;
        for(int i = 1; i <= m; i ++ ){
            x = read(), y = read(), z = read(); edge[i] = {x, y, z, 0};
        }
        sort(edge + 1, edge + 1 + m, cmp);
        for(int i = 1; i <= m; i ++ ){
            int tmpx = find(edge[i].x), tmpy = find(edge[i].y);
            if(tmpx != tmpy){
                p[tmpy] = tmpx; edge2[ ++ idx_edge2] = edge[i];
            }
        }
        for(int i = 1; i <= K; i ++ ){
            val[i] = read(); int op = 1;
            for(int j = 1; j <= n; j ++ ) a[i][j] = read();
            for(int j = 2; j <= n; j ++ ) if(a[i][j] < a[i][op]) op = j;
            val[i] += a[i][op];
            for(int j = 1; j <= n; j ++ ){
                if(j != op) edge2[ ++ idx_edge2] = {op, j, a[i][j], i};
            }
        }
        sort(edge2 + 1, edge2 + 1 + idx_edge2, cmp);
        int ans = INF;
        for(int i = 0; i < (1 << K); i ++ ){
            int res = 0;
            for(int j = 0; j < K; j ++ ) if((i >> j) & 1) res += val[j + 1];
            for(int j = 1; j <= n; j ++ ) p[j] = j;
            for(int j = 1; j <= idx_edge2; j ++ ){
                if(edge2[j].op == 0 || ((i >> (edge2[j].op - 1)) & 1)){
                    int tmpx = find(edge2[j].x), tmpy = find(edge2[j].y);
                    if(tmpx != tmpy){
                        p[tmpy] = tmpx; res += edge2[j].z;
                    }
                }
            }
            ans = min(ans, res);
        }
        cout<<ans<<'\n';
        return 0;
    }
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    return YYY::main();
}
/*
g++ road.cpp -o road -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\road.exe < a.in > a.out

g++ road.cpp -o road -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\road.exe < D:\CQ-S00423\road\road1.in > a.out && fc a.out D:\CQ-S00423\road\road1.ans
.\road.exe < D:\CQ-S00423\road\road2.in > a.out && fc a.out D:\CQ-S00423\road\road2.ans
.\road.exe < D:\CQ-S00423\road\road3.in > a.out && fc a.out D:\CQ-S00423\road\road3.ans
.\road.exe < D:\CQ-S00423\road\road4.in > a.out && fc a.out D:\CQ-S00423\road\road4.ans

*/