#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int MOD = 998244353;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = n;
    for(int i = 1, x; i <= n; ++i){
        cin >> x;
        if(x == 0){
            cnt--;
        }
    }
    cout << cnt << '\n';
    if(cnt < m){
        cout << 0 << '\n';
        return 0;
    }
    i64 res = 1;
    for(int i = 1; i <= cnt; ++i){
        res = res * i % MOD;
    }
    cout << res << '\n';
    return 0;
}
