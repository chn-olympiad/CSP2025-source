#include <bits/stdc++.h>
#define ll long long
const ll mod = 998244353;
const ll N = 5005;
using namespace std;
ll n,ans;
ll a[N],sum[N],s;
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    bool flag = true;
    for(ll i = 1;i <= n;i++) {
        scanf("%lld",&a[i]);
        if(a[i] != a[i - 1] && i != 1) flag = false;
    }
    if(flag) {
        printf("%lld",n * (n - 1) * (n - 2) / 6);
        return 0;
    }
    if(n == 3) {
        if(a[1] + a[2] > a[3] && abs(a[1] - a[2]) < a[3])
            printf("1");
        else
            printf("0");
        return 0;
    }
    sort(a + 1,a + n + 1,greater<ll>());
    for(ll i = 1;i <= n;i++)
        sum[i] = sum[i - 1] + a[i];
    for(ll i = 3;i <= n;i++) {
        for(ll j = i;j <= n;j++) {
            for(ll k = j - i + 1;k < j;k++)
                s += a[k];
            if(s > a[j]) ans = (ans + 1) % mod;
        }
    }
    printf("%lld",ans % mod);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
