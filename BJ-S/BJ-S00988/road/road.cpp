#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15], ans;
bool f[10005] = {false};
struct{
    int u, v, w;
}r[1000005];
bool complete(){
    for (int i = 1;i <= n;i++){
        if (f[i] == false) return false;
    }
    return true;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++){
        cin >> r[i].u >> r[i].v >> r[i].w;
    }
    for (int i = 1;i <= k;i++){
        cin >> c[i];
    }
    while (complete){
        int min1 = 1e9, min2 = 1e9, minn1 = 1, minn2 = 1;
        for (int i = 1;i <= m;i++){
            if (!(r[i].w)){
                if (r[i].w < min1){
                    min1 = r[i].w;
                    minn1 = i;
                }
            }
        }
        for (int i = 1;i <= k;i++){
            if (!c[i]){
                if (c[i] < min2){
                    min2 = c[i];
                    minn2 = i;
                }
            }
        }
        if (min1 < min2){
            f[r[minn1].u] = true;
            f[r[minn2].v] = true;
            ans += min1;
        }
        else{
            ans += min2;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}