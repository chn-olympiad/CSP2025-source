#include <iostream>
using namespace std;

int a[5005], ans, n;
const int mod = 998244353;

void dfs(int d, int cnt, int maxx, int sum){
    if (d <= n && cnt >= 3 && sum > 2 * maxx){
        ans = (ans + 1) % mod;
    }
    for (int i = d; i <= n; i++){
        dfs(i + 1, cnt + 1, max (maxx, a[i]), sum + a[i]);
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    dfs(0, 0, 0, 0);
    cout << ans;
    return 0;
}
