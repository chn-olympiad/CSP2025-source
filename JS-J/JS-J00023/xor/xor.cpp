#include <bits/stdc++.h>
const int N = 5e5 + 5;
#define ll long long
using namespace std;
ll n,k;
ll a[N],ans = 0;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    bool flag = true;
    for(ll i = 1;i <= n;i++) {
        scanf("%lld",&a[i]);
        if(a[i] != 1) flag = false;
    }
    if(n == 1) {
        if(a[1] == k) printf("1");
        else printf("0");
        return 0;
    }
    if(flag) {
        if(k == 0) {
            if(n % 2 == 1) printf("0");
            else printf("%lld",n / 2);
        }
        if(k == 1) {
            printf("%lld",n);
        }
        return 0;
    }
    ll t = 0;
    for(ll i = 1;i <= n;i++) {
        t ^= a[i];
        if(t == k)
            ans++,t = 0;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
