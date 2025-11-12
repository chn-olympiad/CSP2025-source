#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;
int n;
int a[N];
int mod = 998244353;

bool cmp(int a , int b) {
    return a > b;
}

int main() {
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    long long ans = 0;
    sort(a + 1 , a+ n + 1 , cmp);
    for (int i=1;i<=n-2;i++) {
        for (int j=i+1;j<=n-1;j++) {
            for (int z=j+1;z<=n;z++) {
                int maxn = a[i];
                long long h = a[i] + a[j] + a[z];
                if (maxn * 2 < h) {
                    ans = ((ans % mod) + ((((n - z) + 1) * (n - z) / 2) % mod)) % mod;
                    ans = (ans + 1) % mod;
                }else {
                    for (int k=z + 1;k<=n;k++) {
                        h += a[k];
                        if (maxn * 2 < h) {
                            ans = ((ans % mod) + ((((n - k) + 1) * (n - k) / 2) % mod)) % mod;
                            ans = (ans + 1) % mod;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<ans % mod;
    return 0;
}
