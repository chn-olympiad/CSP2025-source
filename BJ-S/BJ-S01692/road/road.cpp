#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+10, maxk = 15, maxm = 1e4+10;;
int n, m, k;
struct node{
    int u, v, w;
};
node edges[maxn];
int fa[maxn];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    fa[find(x)] = find(y);
}
bool cmp(node x, node y){
    return x.w < y.w;
}
int c[maxn];
int a[maxk][maxn];
int ve[maxm][maxm];
int ans = INT_MAX;
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    if(k == 0){
        for(int i = 1;i <= m;i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        sort(edges+1, edges+m+1, cmp);
        int cnt = n-1;
        int ans = 0;
        for(int i = 1;i <= n;i++) fa[i] = i;
        for(int i = 1;i <= m;i++){
            if(cnt == 0) break;
            int x = edges[i].u, y = edges[i].v;
            if(find(x) != find(y)){
                merge(x, y);
                ans += edges[i].w;
                cnt--;
            }
        }
        cout << ans;
    }
    else{
        for(int i = 1;i <= m;i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        bool flag = true;
        for(int i = 1;i <= k;i++){
            cin >> c[i];
            if(c[i] != 0) flag = false;
            for(int j = 1;j <= n;j++){
                cin >> a[i][j];
                if(a[i][j] != 0) flag = false;
            }
        }
        if(flag) cout << 0;
        else{
            sort(edges+1, edges+m+1, cmp);
            int cnt = n-1;
            int ans = 0;
            for(int i = 1;i <= n;i++) fa[i] = i;
            for(int i = 1;i <= m;i++){
                if(cnt == 0) break;
                int x = edges[i].u, y = edges[i].v;
                if(find(x) != find(y)){
                    merge(x, y);
                    ans += edges[i].w;
                    cnt--;
                }
            }
            cout << ans;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
