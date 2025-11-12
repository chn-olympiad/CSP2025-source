#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans, b[5005];

void dfs(int pos, int k){
    if (pos == n + 1){
        int num = 0;
        for (int i = 1; i <= k; i++) num += b[i];
        if (num > b[k] * 2) ans++;
        return;
    }
    for (int i = 0; i <= 1; i++){
        if (i){
            b[++k] = a[pos];
            dfs(pos + 1, k);
        }
        else dfs(pos + 1, k);
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0);
    cout << ans;
    return 0;
}
