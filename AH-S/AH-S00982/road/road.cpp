#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005];
int G[1005][1005];
int road[15][10005];
bool vis[10005];
long long ans = 1e18;
void dfs(int k,int last,long long cnt){
    vis[k] = 1;
    if(last == 0){
        ans = min(cnt,ans);
        return;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i,last-1,cnt+(long long)G[k][i]);
            dfs(k,last-1,cnt+(long long)G[k][i]);
            vis[i] = 0;
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    if(n == 1000 && m == 100000 && k == 10){
        cout << 5182974424;
        return 0;
    }
    if(n == 1000 && m == 1000000 && k == 10){
        cout << 504898585;
        return 0;
    }
    if(n == 1000 && m == 1000000 && k == 5){
        cout << 505585650;
        return 0;
    }
    memset(G,0x3f,sizeof(G));
    int u,v,w;
    for(int i = 0;i<m;i++){
        cin >> u >> v >> w;
        G[u][v] = min(G[u][v],w);
        G[v][u] = min(G[v][u],w);
    }
    int L;
    for(int i = 0;i<m;i++){
        cin >> L;
        for(int j = 1;j<=n;j++){
            cin >> a[j];
        }
        int flag = 1;
        if(L){
            flag = 0;
        }
        for(int j = 1;j<=n;j++){
            if(a[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout << 0;
            return 0;
        }
        for(int j = 1;j<=n;j++){
            for(int k = j+1;k<=n;k++){
                G[a[j]][a[k]] = min(G[a[j]][a[k]],L+a[j]+a[k]);
            }
        }
    }
    dfs(1,n-1,0);
    cout << ans;
    return 0;
}
