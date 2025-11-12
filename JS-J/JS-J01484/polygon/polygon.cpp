#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int a[5005],ans = 0,n;
void dg(int dep,int sum,int maxn){
    if (dep > n){
        if (sum > maxn * 2) ans++;
    }else{
        dg(dep + 1,sum,maxn);
        dg(dep + 1,sum + a[dep],max(a[dep],maxn));
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    dg(1,0,INT_MIN);
    cout << ans % MOD;
    return 0;
}
