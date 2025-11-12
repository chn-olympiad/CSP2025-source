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
constexpr ll N = 1e5 * 5 + 1;
constexpr ll inf = 0xffffffffffffffLL;

struct IOFiles{
    cstr in, out;
    const bool no_in = 0, no_out = 0;
};


o4 void init(IOFiles &file){
    cstr in = file.in, out = file.out;
    if (in != ""){
        if (!file.no_in)freopen(in, "r", stdin);
        if (!file.no_out)freopen(out, "w", stdout);
    }
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

uint a[N];

Redirect(file){"xor.in", "xor.out"};
def solve(){
    ll n, k; cin >> n >> k;
    ll l=0, r=0;
    for(ll i = 0;i < n;i ++){
        cin >> a[i];
    }
    int ans = 0;
    uint val = 0;
    while(r < n){
        val ^= a[r];
        if (val == k){
            ans ++;
            l = r+1;
            val = 0;
        }
        r++;
    }
    cout << ans << endl;
}


int main(){
    init(file);
    solve();
}