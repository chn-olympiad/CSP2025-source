#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 5;
ll n, k, a[MAXN], xo[MAXN], ans = 0LL, lef = 0LL;
map<ll, pair<ll, bool> > mp;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for(ll i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        xo[i] = xo[i - 1] ^ a[i];
    }
    mp[0LL].second = true;
    for(ll i = 1;i <= n;i++){
        ll pur = xo[i] ^ k;
        if(mp[pur].second && mp[pur].first >= lef){
            lef = i;
            ans++;
        }
        mp[xo[i]].first = i;
        mp[xo[i]].second = true;
    }
    printf("%lld\n", ans);
    return 0;
}
