#include<bits/stdc++.h>
using namespace std;
#define rep(a) for(int i = 0;i < a;i++)
#define repj(a) for(int j = 0;j < a;j++)
typedef long long ll;
typedef pair<int,int> pi;
const int mod = 998244353,N = 5e3 + 10;
int a[N];
int pw(ll a,int b){
    ll r = 1;
    while (b){
        if (b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,ans = 0;
    bool f = 1;
    cin >> n;
    rep(n){
        cin >> a[i];
        if (a[i] != 1) f = 0;
    }
    if (f){
        cout << ((ll)pw(2,n) - n - 1 - (ll)n * (n - 1) / 2 + mod) % mod << endl;
    }
    else{
        rep((1 << n)){
            int m = 0,sum = 0,mx = 0;
            repj(n){
                if ((i >> j) & 1) m++,sum += a[j],mx = max(mx,a[j]);
            }
            if (m >= 3 && sum > mx * 2) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
