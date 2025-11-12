#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int Mod = 998244353;
int a[N], n, ans, sum[N];

void dfs(int x, int sum, int mx){
    if(x > n) return ;
    if(sum > mx * 2){
        ans++;
        if(ans > Mod) ans %= Mod;
    }
    for(int i = x + 1; i <= n; i++){
        dfs(i, sum + a[i], max(mx, a[i]));
    }
}

int main() {

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    dfs(0, 0, 0);

    cout << ans << endl;


    return 0;
}