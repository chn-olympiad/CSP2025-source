#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5010, mod = 998244353;
int n, a[N];
long long ans;
long long fac[510];
long long qpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod, b >>= 1;
    }
    return res;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(n > 25){
        fac[1] = 1;
        for(int i = 2; i <= n; ++i) fac[i] = fac[i-1]*i%mod;
        for(int i = 3; i <= n; ++i){
            long long c = fac[n]%mod*qpow(fac[i], mod-2)%mod*qpow(fac[n-i], mod-2)%mod;
            ans = (ans+c)%mod;
        }
        cout << ans+1;
    }else{
        for(int mask = 1; mask < (1<<n); ++mask){
            int mx = -1, sum = 0;
            for(int i = 0; i < n; ++i)
                if(mask&(1<<i))
                    mx = max(mx, a[i]), sum += a[i];
            if(sum > mx*2) ans = (ans+1)%mod;
        }
        cout << ans;
    }
    return 0;
}
