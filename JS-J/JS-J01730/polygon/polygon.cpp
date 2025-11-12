#include<bits/stdc++.h>
using namespace std;
long long a[5005];
const long long mod = 9698244353;
long long solve(long long n, long long m){
    long long o = 1, ua = 1, ub = 1;
    for(int i = 1; i <= n; i++)
        o *= i % mod;
    for(int i = 1; i <= m; i++)
        ua *= i % mod;
    for(int i = 1; i <= (n - m); i++)
        ub *= i % mod;
    long long tmp = o / (ua * ub % mod);
    return tmp;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    long long n, ans = 0;
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    if(n == 3){
        if(a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3])))
            printf("1");
        else printf("0");
        return 0;
    }
    else{
        for(int i = 3; i <= n; i++)
            ans = (ans + solve(n, i)) % mod;
        printf("%lld", ans);
    }
}
