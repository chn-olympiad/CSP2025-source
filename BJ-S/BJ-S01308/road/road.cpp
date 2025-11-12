#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxm = 1e6 + 10;
const int maxn = 1e4 + 10;
const int maxk = 10 + 2;
const ll inf = 1e16;
int vis[maxn];
int ind[maxn];
int a[maxk][maxn];
struct Node{
    int u, v, w;
}p[maxm];
vector<int> e[maxn];
int dis[maxn][maxn];
int c[maxk];
int n, m, k;
ll ans;
void dfs(int x, int cnt, ll sum){
    if(cnt == n){
        ans = min(ans, sum);
        return;
    }
    if(sum >= ans) return;
    for(auto i : e[x]){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i, cnt + 1, sum + dis[x][i]);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> p[i].u >> p[i].v >> p[i].w;
        int x = p[i].u, y = p[i].v, z = p[i].w;
        e[x].push_back(y);
        e[y].push_back(x);
        //cout << x << " " << y << "\n";
        dis[x][y] = z;
        dis[y][x] = z;
        ind[x]++;
        ind[y]++;
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    ans = inf;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 1){
            dfs(i, 1, 0ll);
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
