#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int jc(int n) {
    int res = 1;
    for(int i=2; i<=n; i++) res = (res*i)%mod;
    return res;
}
int n,a[5005],ans,maxn = -1;
signed main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin  >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        maxn = max(a[i],maxn);
    }
    if(maxn == 1) {
        for(int i=3; i<=n; i++)
            ans += (jc(n)/jc(i)/jc(n-i))%mod;
    }
    else if(n == 3) {
        if(a[1] + a[2] + a[3] > maxn*2) ans = 1;
    }
    cout << ans;
    return 0;
}
