#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct idk{
    int u, v, w;
};
idk a[1000010];
bool b[100010];
bool cmp(idk x, idk y){
    return x.w < y.w;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[i] = {u, v, w};
    }
    sort(a + 1, a + m + 1, cmp);
    int ans = 0, cnt = 0;
    for(int i = 1; i <= m; i++){

        int u = a[i].u, v = a[i].v, w = a[i].w;

        if(b[u] && b[v]) continue;
        ans += w;
        b[u] = true;
        b[v] = true;
        cnt++;



        if(cnt == n - 1) break;
    }
    cout<<ans;
    return 0;
}
