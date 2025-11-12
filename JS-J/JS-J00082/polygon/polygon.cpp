#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, ans;
int a[5005];

void dfs(int i, int sum, int cnt){
    if (i > n){
        return;
    }
    // Check for answers if there's already 2 edges
    if (cnt > 1){
        int j;
        for (j = i; j <= n; j ++){
            if (a[j] >= sum) {
                break;
            }
        }
        ans = (ans + j - i) % MOD;
    }
    // Add a new edge if there's more than 1 edge left
    if (i > n - 1) return;
    for (int j = i; j <= n; j ++){
        dfs(j + 1, sum + a[j], cnt + 1);
    }
}

int main(){
    // Only 1-10
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
