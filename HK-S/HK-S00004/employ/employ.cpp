#include <bits/stdc++.h>
using namespace std;
#define tendoualice
#ifdef tendoualice
ifstream input("employ.in");
ofstream output("employ.out");
#define cin input
#define cout output
#endif

#define ll long long

const ll MOD = 998244353;
const int maxn = 510;

ll Pow(ll a, ll b){
    ll out = 1, base = a;
    while(b != 0){
        if(b & 1) out *= base;
        base *= base, b >>= 1;
    }
    return out;
}

ll fac[maxn], inv[maxn];

void init(){
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    inv[maxn - 1] = Pow(fac[maxn - 1], MOD - 2);
    for(int i = maxn - 2; i >= 0; i--) inv[i] = inv[i + 1] * i;
}

void solve(){
    init();
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zero++;
        else one++;
    }
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c, c + n);
    if(m == n){
        cout << (fac[one] * inv[zero]) % MOD << endl;
        return;
    } else if(m == 1){
        int maxc = c[n - 1];
        if(n >= 2 and c[n - 2] == c[n - 1]){
            cout << 0 << endl;
            return;
        } else{
            int secmaxc = c[n - 2];
            if(secmaxc > zero){
                cout << 0 << endl;
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
// g++ -O2 -std=c++14 -static employ.cpp -o employ