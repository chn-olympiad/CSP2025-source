#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int MOD = 998244353;
long long prefix[N];
int n;
void init(){
    prefix[1] = 1;
    for(int i = 2;i <= n;i++){
        prefix[i] = (prefix[i - 1] % MOD * i % MOD) % MOD;
    }
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int ans = 0;
    init();
    for(int i = 3;i < n;i++){
        if(i == n - 1){
            ans += n % MOD;
        }else{
            ans += ((prefix[n] / prefix[n - i]) / prefix[i]) % MOD;
        }
    }
    cout << ans + 1 << '\n';
    return 0;
}
//expect:24pts
