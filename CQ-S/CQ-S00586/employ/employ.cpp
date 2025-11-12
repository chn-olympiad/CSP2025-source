#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'

void solve() {
    long long n,m; cin >> n >> m;
    long long cnt=0,mul=1;
    for (long long i=1;i<=n;i++) {
        char c; cin >> c;
        if (c=='1') mul*=++cnt,mul%=998244353;
    }
    cout << mul << endl;
}
int main() {
    #define CONTEST
    
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    #endif
    #endif

    long long T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}