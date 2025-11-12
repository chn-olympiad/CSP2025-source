#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 25;
const int maxm = 2e6 + 5;

int n, m, k;
struct edge{
    int u, v;
    long long w;
} e[maxm];
int fa[maxn];

void init(int n){
    for(int i = 1;i <= n;i++)fa[i] = i;
}

int find(int a){
    if(fa[a] == a)return a;
    return fa[a] = find(fa[a]);
}

bool Merge(int a, int b, int n){
    a = fa[a];
    b = fa[b];
    if(a == b)return false;
    for(int i = 1;i <= n;i++){
        if(fa[i] == b)fa[i] = a;
    }
    return true;
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

long long Kruskal(int n, int m){
    sort(e + 1, e + m + 1, cmp);
    long long ans = 0;
    for(int i = 1;i <= m;i++){
        if(Merge(e[i].u, e[i].v, n)){
            ans += e[i].w;
            n--;

            if(n == 1)return ans;
        }
    }
}
bool vis[15];
long long c[15], a[15][maxn], sum = 0x3f3f3f3f;

void dfs(int t){
    if(t > k){
        int nt = n, bt = m;
        long long res = 0;
        for(int i = 1;i <= k;i++){
            if(vis[i]){
                nt++;
                res += c[i];
                for(int j = 1;j <= n;j++){
                    bt++;
                    e[bt].u = nt;
                    e[bt].v = j;
                    e[bt].w = a[i][j];
                }
            }
        }init(nt);
        res += Kruskal(nt, bt);
        sum = min(sum, res);
        return ;
    }dfs(t + 1);
    vis[t] = true;
    dfs(t + 1);
    vis[t] = false;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    init(n);
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }if(k == 0){
        cout << Kruskal(n, m) ;
        return 0;
    }for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }dfs(1);
    cout << sum;
    return 0;
}
