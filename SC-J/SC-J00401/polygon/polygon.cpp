#include <bits/stdc++.h>
#define i64 long long
using namespace std;

i64 n;
const i64 N = 5e3 + 3,mod = 998244353;
i64 a[N],ans = 0;

i64 cc(i64 x){
    i64 res = 0;
    while(x){
        if(x & 1) res++;
        x >>= 1;
    }
    return res;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(i64 i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for(i64 i = 3;i <= n;i++){
        for(i64 j = 1;j < (1 << (i - 1));j++){
            if(cc(j) < 2) continue;
            i64 now = 0;
            for(i64 k = 1;k < i;k++){
                if(j & (1 << (k - 1))){
                    now += a[k];
                }
            }
            if(now > a[i]) ans = (ans + 1) % mod;
        }
    }
    printf("%lld",ans);
    return 0;
}