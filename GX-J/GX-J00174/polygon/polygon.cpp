#include<bits/stdc++.h>
using namespace std;
const long long P = 998244353;
long long n,a[5010],x = 1,ans;
inline void clec(){
    ans = 1;
    for (long long i = 1;i <= n;i++){
        ans *= 2;
        if (i != n) ans %= P;
    }
    ans -= (n + 1);
    ans -= n * (n - 1) / 2;
    cout << (ans + P) % P;
}
inline void dfs(long long i,long long x,long long y,long long z){
    if (i == n + 1){
        if (x * 2 < y && z >= 3) ans++,ans %= P;
        return;
    }
    dfs(i + 1,max(x,a[i]),y + a[i],z + 1);
    dfs(i + 1,x,y,z);
}
int main(){
    freopen("w","polygon.in",stdin);
    freopen("r","polygon.out",stdout);
    cin >> n;
    for (long long i = 1;i <= n;i++) cin >> a[i],x = max(x,a[i]);
    if (x == 1) clec();
    else dfs(1,0,0,0),cout << ans;
    return 0;
}
