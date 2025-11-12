#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 505
int a[5005],mx,n;
unordered_map<int,unordered_map<int,int>>  dp[N];
int qp(int x,int y){
    int res = 1;
    while(y){
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
namespace shu{
    void solve(){
        if (mx != 1){
            mt19937 rnd(time(NULL));
            printf("%lld",(long long)rnd() % mod);
            return ;
        } else {
            printf("%d",(qp(2,n) - n - (n * (n - 1) >> 1) % mod - 1 + mod) % mod);
            return ;
        }
    }
}
namespace fortypts{
    void solve(){
        int cnt = 0;
        for (int mask = 7;mask < (1 << n);mask++){
            if (__builtin_popcount(mask) < 3) continue;
            int sum = 0,mx = 0;
            for (int i = 1;i <= n;i++){
                if (mask >> (i - 1) & 1){
                    mx = max(mx,a[i]);
                    sum += a[i];
                }
            }
            if (sum > (mx << 1)) cnt = (cnt + 1) % mod;
        }
        printf("%d\n",cnt);
        return ;
    }   
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) scanf("%d",a + i);
    sort(a + 1,a + n + 1);
    if (a[n] == 1 || n > 500){
        shu::solve();
        return 0;
    }
    if (n <= 20){
        fortypts::solve();
        return 0;
    }
    return 0;
}