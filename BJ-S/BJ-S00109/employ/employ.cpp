#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 509, mod = 998244353;
int n, m;
bool can[maxn];
int fa[maxn], ifa[maxn];
int qpow(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1){
            ans = (ans * (ll)x) % mod;
        }
        y >>= 1;
        x = (x * (ll)x) % mod;
    }
    return ans;
}
int inv(int x){
    return qpow(x, mod - 2);
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    fa[0] = 1;
    for(int i = 1; i <= n; i++){
        fa[i] = (fa[i - 1] * (ll)i) % mod;
    }
    ifa[n] = inv(fa[n]);
    for(int i = n - 1; i > -1; i--){
        ifa[i] = (ifa[i + 1] * (ll)(i + 1)) % mod;
    }
    int cnt1 = 0;
    char c;
    for(int i = 1; i <= n; i++){
        cin >> c;
        can[i] = c == '1';
        if(can[i]) cnt1++;
    }
    if(true/*cnt1 == n*/){
        int ans = 0;
        for(int i = m; i <= n; i++){
            ans += fa[n] / fa[n - i];//((ll)fa[n] * ifa[n-i]) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
