#include<bits/stdc++.h>
#define int long long
using namespace std;//40-60
const int N = 5e3 + 3;
const int mod = 998244353;
int n, maxv, cnt = 0;
int a[N], tmp[N], p[N];
inline int max(int x, int y){
    return x > y ? x : y;
}
inline bool solve(int s){
    int m = s, tot = 0;
    while(m){
        tmp[++tot] = (m & 1);
        m >>= 1;
    }
    int Mx = -1, Sum = 0;
    for(int i = 1; i <= n; i++){
        if(tmp[i]){
            Mx = max(Mx, a[i]);
            Sum += a[i];
        }
    }
    return Sum > Mx * 2;
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(n == 3){
        if(a[1] + a[2] > a[3]) cout << 1;
        else cout << 0;
        return 0;
    }
    if(a[n] <= 1){
        int ans = 1ll;
        for(int i = 1; i <= n; i++){
            ans <<= 1ll;
            ans %= mod;
        }
        ans -= 1ll - n - (n * (n - 1) >> 1ll);
        ans += mod;
        ans %= mod;
        cout << ans << "\n";//i[3-n]:c(n,i)
        return 0;
    }
    for(int s = 1; s < (1ll << n); s++){
        if(solve(s)) cnt++;
        if(cnt >= mod) cnt -= mod;
    }
    cnt %= mod;
    cout << cnt << "\n";
    return 0;
}
