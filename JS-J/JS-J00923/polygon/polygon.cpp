#include <cstdio>
#include <algorithm>
#include <vector>
#define uint unsigned long long
#define sint long long
const int maxn = 5005, mod = 998244353;
int a[maxn], n;
inline int maxv(int a, int b){
    return a > b ? a : b;
}
bool check(int c){
    int m = 0, s = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(c >> i & 1){
            cnt ++;
            m = maxv(m, a[i]);
            s += a[i];
        }
    } 
    return cnt >= 3 && s > (m << 1);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int m = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) m = maxv(m, a[i]);
    if(m > 1){
        int res = 0;
        for(int i = 0; i < (1 << n); i++) res += check(i);
        printf("%d\n", res);
    }
    else{
        int res = 1;
        for(int i = 0; i < n; i++) res = res * 2ll % mod;
        res = (res * 1ll + mod - 1 - n - (n * 1ll * (n - 1) / 2)) % mod;
        printf("%d\n", res);
    }
    
    return 0;
}