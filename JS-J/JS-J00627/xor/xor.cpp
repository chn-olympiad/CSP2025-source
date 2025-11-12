#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a[1000001], p[1000001], t[1000001], tmp, ans;
map<ll, ll> mp;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        p[i] = p[i - 1] ^ a[i];
        t[i] = mp[p[i] ^ k];
        mp[p[i]] = i;
        if(p[t[i]] != (p[i] ^ k) || t[i] < 0 || t[i] >= i) t[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        if(t[i] == -1) continue;
        if(t[i] >= tmp) tmp = i, ans++;
    }
    printf("%lld", ans);
    return 0;
}
