#include <bits/stdc++.h>
#define N 105
#define ll long long
using namespace std;
ll n,m;
ll a[N];
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i = 1;i <= n * m;i++) {
        scanf("%lld",&a[i]);
    }
    ll k = a[1],t;
    sort(a+1,a+n*m+1,greater<ll>());
    for(ll i = 1;i <= n * m;i++) {
        if(a[i] == k)
            t = i;
    }
    /*for(int i = 1;i <= n * m;i++)
        cout << a[i];
    cout << t;*/
    ll c = ceil(1.0 * t / n),r = t % n;
    if(r == 0) {
        if(c % 2 == 1) r = m;
        else r = 1;
    }
    if(c % 2 == 0) {
        r = m + 1 - r;
    }
    printf("%lld %lld",c,r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
