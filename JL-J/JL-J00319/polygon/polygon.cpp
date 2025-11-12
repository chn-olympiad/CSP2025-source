#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5005;
const ll mod = 998244353;

ll f[N][N], n, a[N], ans, maxn, g[N][N];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (int i = 3; i <= n; i++){
        for (int l = 1; l < i; l++){
            for (int r = l+1; r < i; r++){
                if (a[l]+a[r]>a[i]) f[i][3]++;
                if (a[l]+a[r]>=a[i]) g[i][3]++;
            }
        }
    }
    for (int j = 4; j <= n; j++){
        for (int i = j; i <= n; i++){
            ll k = a[i]/2+1;
            ll l = lower_bound(a+1,a+i+1,k)-a;
            ll r = i-1;
            for (int x = l; x <= r; x++) f[i][j] = (f[i][j]+g[x][j-1])%mod;
            k = a[i]/2+(a[i]%2);
            l = lower_bound(a+1,a+i+1,k)-a;
            r = i-1;
            for (int x = l; x <= r; x++) g[i][j] = (g[i][j]+g[x][j-1])%mod;
            for (int x = 1; x < i; x++){
                f[i][j] = (f[i][j]+f[x][j])%mod;
                g[i][j] = (g[i][j]+g[x][j])%mod;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 3; j <= n; j++) ans = (ans+f[i][j])%mod;
    }
    cout << ans;
    return 0;
}
