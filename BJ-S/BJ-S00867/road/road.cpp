#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 1e4+10;
int a[20][N], G[N][N];
struct Edge{
    int u, v, w;
}E[1000010];
int f[N];
void init(){
    for(int i=1; i<=n; i++){
        f[i] = i;
    }
}
int find(int x){
    if(f[x]==x) return x;
    return f[x] = find(f[x]);
}
bool cmp(Edge x, Edge y){
    return x.w < y.w;
}
long long kruskal(){
    init();
    int cnt=0;
    long long ans=0;
    sort(E+1, E+1+m, cmp);
    for(int i=1; i<=m; i++){
        int u = E[i].u, v = E[i].v, w = E[i].w;
        //printf(":%d %d %d\n", u, v, w);
        if(find(u)!=find(v)){
            cnt++;
            ans += w;
            f[find(u)] = find(v);
        }
        if(cnt >= n) break;
    }
    return ans;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[v][u] = w;
        G[u][v] = w;
        //printf(":%d %d %d\n", E[i].u, E[i].v, E[i].w);
    }
    int pn = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(G[i][j]){
                E[pn].u = i;
                E[pn].v = j;
                E[pn++].w = G[i][j];
            }
        }
    }
    bool flag = true;
    long long ans=kruskal();
    for(int i=1; i<=k; i++){
        scanf("%d", &a[i][0]);
        //if(a[i][0]!=0) flag = false;
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            E[pn].u = n+1;
            E[pn].v = j;
            E[pn++].w = a[i][j];
        }
        n++;
        m+=n;
        ans = max(ans, kruskal());
    }
    /*if(flag){
        int nn = n;
        for(int i=1; i<=k; i++){
            for(int j=1; j<=nn; j++){
                for(int x=j+1; x<=nn; x++){
                    if(a[i][j]+a[i][x] < G[j][x]){
                        G[j][x] = a[i][j]+a[i][x];
                        G[x][j] = a[i][j]+a[i][x];
                    }
                }
            }
        }
        int pn = 1;
        for(int i=1; i<=nn; i++){
            for(int j=1; j<=i; j++){
                if(G[i][j]){
                    E[pn].u = i;
                    E[pn].v = j;
                    E[pn++].w = G[i][j];
                }
            }
        }
        long long ans = kruskal();
        printf("%lld", ans);
    }*/
    printf("%lld", ans);
    return 0;
}//1146382605 1159672104