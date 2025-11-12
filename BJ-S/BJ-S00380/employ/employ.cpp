#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fLL, mod = 998244353;
int n, m, c[505], sum = 0, cnt[505], precnt[505], p[505];
long long dp[505][505][505], ans = 0;
string s;
inline int mn(){
    for(int i = 1;i <= n;i++){
        if(s[i] == '0'){
            return 0;
        }
        if(c[i] == 0){
            return 0;
        }
    }
    ans = 1;
    for(int i = 1;i <= n;i++){
        ans = ans * i % mod;
    }
    return ans;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        cnt[c[i]]++;
        p[i] = i;
    }
    for(int i = 1;i <= n;i++){
        precnt[i] = precnt[i - 1] + cnt[i];
    }
    sort(c + 1, c + n + 1);
    if(m == n){
        cout << mn() << "\n";
        return 0;
    }
    do{
        int now = 0;
        for(int i = 1;i <= n;i++){
            if(s[i - 1] == '0'){
                now++;
            }
            else{
                if(now >= c[p[i]]){
                    now++;
                }
            }
        }
        if(n - now >= m){
            ans++;
            ans %= mod;
        }
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << "\n";
    return 0;
}
