// I can't find how to solve this problem
// how?
// maybe 100 + 100 + 100 + 40 = 340
// maybe 100 + 100 + 80 + 20 = 300
#include <iostream>
#include <algorithm>
typedef long long ll;
const int N = 5010;
const ll MOD = 998244353;
using namespace std;
ll n, a[N], ans;
void dfs(int x, ll maxn, ll sum) {
    if(x > n) {
        if(sum > maxn * 2) {
            ans = (ans + 1) % MOD;
        }
        return;
    }
    dfs(x + 1, maxn, sum);
    dfs(x + 1, max(maxn, a[x]), sum + a[x]);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}