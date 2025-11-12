#include <bits/stdc++.h>
using namespace std;

#define def auto
#define o4 inline
#define Redirect(var) IOFiles var

using ll = long long ;
using ull = unsigned long long ;
using uint = unsigned int ;
using cstr = const char *;

#define endl '\n';
constexpr ll N = 1e6;
constexpr ll inf = 0xffffffffffLL;
constexpr ll Mod = 998244353;

struct IOFiles{
    cstr in, out;
    const bool no_in = false, no_out = false;
};


o4 void init(IOFiles &file){
    cstr in = file.in, out = file.out;
    if (in != ""){
        if (! file.no_in) freopen(in, "r", stdin);
        if (!file.no_out) freopen(out, "w", stdout);
    }
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

o4 ll C(ll n, ll m){
    // n xuan m
    ll ans = 1;
    for(ll i = m+1;i <= n;i ++) ans *= i;
    for(ll i = 2;i <= n-m;i ++) ans /= i;
    return ans;
}

ll a[N];

def solve_3(ll n){
    ll ans = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = i+1;j <= n;j ++){
            for(int k = j+1;k <= n;k ++){
                if (a[j] + a[k] > a[i]) ans++;
                for(int l = k+1;l <= n;l ++){
                    if (a[j] + a[l] > a[i]) ans++;
                    if (a[k] + a[l] > a[i]) ans++;
                    if (a[j] + a[k] + a[l] > a[i]) ans++;
                }
            }
        }
    }
    return ans;
}

Redirect(file){"polygon.in", "polygon.out"};
def solve(){
    ll n; cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, [](int a, int b){
        return a > b;
    });
    ll ans = solve_3(n);
    cout << ans % Mod;
}


int main(){
    init(file);
    solve();
}