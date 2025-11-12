// emm T3 is not so easy
// but the code thinks it's easy (
#include <iostream>
#include <map>
const int N = 500010;
using namespace std;
int n, k, a[N], dp[N], pre[N];
map<int, int> mp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(mp.find(pre[i] ^ k) != mp.end())
            dp[i] = max(dp[i], dp[mp[pre[i] ^ k]] + 1);
    }
    cout << dp[n] << endl;
    return 0;
}