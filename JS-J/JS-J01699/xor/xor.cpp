#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a[500005], ans;
set <ll> st;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    st.insert(k);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i] ^= a[i - 1];
        if(st.find(a[i]) != st.end()){
            ans++;
            st.clear();
        }st.insert(a[i] ^ k);
    }cout << ans;
    return 0;
}
