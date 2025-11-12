#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long n,m;
unsigned long long ans = 1;
long long a[1005];
string s;

unsigned long long p(long long n,long long m){
    unsigned long long res = 1;
    for (int i = n;i >= n - m + 1;i--){
        res *= i;
        res %= mod;
    }
    return res % mod;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    s = " " + s;
    for (int i = 1;i <= n;i++){
        if (s[i] == '1'){
            if (a[i] != 0) ans *= p(a[i],m) % mod;
        }else{
            if (a[i] != 0) ans *= p(a[i],1) % mod;
        }
    }
    cout << ans % mod;
    return 0;
}
