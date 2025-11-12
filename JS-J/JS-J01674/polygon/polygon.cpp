#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n;
int a[5005];
ll pown(ll x, ll y){
    ll res = 1;
    while(y){
        if(y%2){
            res*=x;
            res%=mod;
        }
        y/=2;
        x*=x;
        x%=mod;
    }
    return res%mod;
}
int sum[5005];
map<pair<int, int>, int> mp;
ll f(int y, int than){
    if(mp[{y, than}]) return mp[{y, than}]-1;
    if(sum[y] <= than) return 0;
    if(than < 0) return pown(2, y);
    if(than == 0) return pown(2, y)-1;
    ll num1 = f(y-1, than), num2 = f(y-1, than-a[y]);
    ll ans = (num1+num2)%mod;
    mp[{y, than}] = ans+1;
    //cout << y << " " << than << ": " << num1 << " " << num2 << " " << ans << endl;
    return ans;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    bool yn = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
        if(a[i] != 1) yn = false;
    }
    if(yn){
        cout << (pown(2, n)-n-1-(n*(n-1))/2+mod)%mod;
    }else{
        sort(a+1, a+n+1);
        ll ans(0);
        for(int i = 3;i <= n;i++){
            ll num = f(i-1, a[i]);
            ans += num;
            ans %= mod;
            //cout << i <<  ": " << num << endl;
        }
        cout << ans;
    }
    return 0;
}
