#include<bits/stdc++.h>
using namespace std;

int n, m, k, t[15], fa[10010], ans = 0, vis[10010], flag = 0;
struct node{
    int u, v, w;
}a[1001000], c[15][100100];

bool cmp(node x, node y){
    return x.w < y.w;
}

int found(int x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = found(fa[x]);
}
void bing(int x, int y, int w){
    int u = found(x), v = found(y);
    if(u != v){
        ans += w;
        fa[u] = v;
    }
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= k; i++){
        cin>>t[i];
        if(t[i] != 0){
            flag = 1;
        }
        for(int j = 1; j <= n; j++){
            if(c[i][j].w != 0){
                flag = 1;
            }
            cin>>c[i][j].w;
            c[i][j].u = i;
            c[i][j].v = j;
        }
    }
    if(flag == 0){
        cout<<0;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    for(int i = 1; i <= m ;i++){
        bing(a[i].u, a[i].v, a[i].w);
    }
    cout<<ans;
    return 0;
}
