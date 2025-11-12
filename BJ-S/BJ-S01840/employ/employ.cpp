#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    const int mod = 998244353;
    int n, m, c[505], sum = 0, q = 1;
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        q *= c[i];
    }
    s = ' ' + s;
    for (int i = 1; i <= s.size(); i++){
        if (int(s[i]) == '1'){
            sum++;
        }
    }cout << sum;
    if (sum < m){
        cout << 0;
        return 0;
    }
    if (sum == s.size() || m == 1){
        int ans = 0;
        for (int i = sum; i >= 1; i--){
            ans *= sum;
        }
        cout << ans % mod;
        return 0;
    }
    cout << q;
    return 0;
}
