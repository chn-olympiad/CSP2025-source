#include<bits/stdc++.h>

using namespace std;

int n, m, k, u, v;
long long ans = 0x3f3f3f3f3f3f3f3f;
bool g[10005][10005];
bool vis[10005][10005];
bool vcity[10005];
int w[10005][10005];
int c[15][10005];
bool vc[15];

bool check(){
    for(int i=1; i<=n; i++){
        if(!vcity[i]){
            return false;
        }
    }
    return true;
}

void dfs(int s, long long sum){
    //cout << s << " " << sum << endl;
    if(check()){
        ans = min(ans, sum);
        return ;
    }
    //cout << ans << endl << endl;

    for(int i=1; i<=n; i++){
        if(g[s][i] && !vis[s][i]){
            vis[s][i] = true;
            vis[i][s] = true;
            vcity[i] = true;
            dfs(i, sum+w[s][i]);
            for(int j=1; j<=k; j++){
                if(!vc[j]){
                    vc[j] = true;
                    dfs(i, sum+c[j][0]+c[j][i]+c[j][s]);
                    vc[j] = false;
                }else{
                    dfs(i, sum+c[j][i]+c[j][s]);
                }
            }
            vis[s][i] = false;
            vis[i][s] = false;
            vcity[i] = false;
        }
    }
    return ;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        cin >> u >> v >> w[u][v];
        w[v][u] = w[u][v];
        g[u][v] = g[v][u] = true;
    }
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            cin >> c[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        vcity[i] = true;
        dfs(i, 0);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
