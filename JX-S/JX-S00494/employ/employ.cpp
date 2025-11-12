#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505, mod = 998244353;
int n, m, c[maxn], fc[maxn], infc[maxn];
char s[maxn];
int qpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
main(){
    freopen("employ3.in", "r", stdin);
    //freopen("employ.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i ++) scanf("%lld", &c[i]);
    fc[0] = 1;
    for(int i = 1; i <= n; i ++) fc[i] = fc[i - 1] * i % mod;
    infc[n] = qpow(fc[n], mod - 2);
    for(int i = n - 1; i >= 0; i --) infc[i] = infc[i + 1] * (i + 1) % mod;
    bool flag = true;
    for(int i = 1; i <= n; i ++) if(s[i] != '1') flag = false;
    if(flag) {
        sort(c + 1, c + n + 1);
        int sum = 0;
        for(int i = 1; i <= n; i ++) if(!c[i]) sum ++;
        int tmp = n - sum;
        if(tmp < m) printf("0\n");
        else printf("%lld\n", );
    }
    return 0;
}
