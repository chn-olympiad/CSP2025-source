#include <bits/stdc++.h>
using namespace std;

const int  maxn = 505;
const int  MOD = 998244353;
int        n, m, ans;
string     s;
int        c[maxn];
int        cnt;
int        p[maxn];
int        tmp[maxn];

void init(){
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
}
void solve(){
    ans = 0;
}
void print(){
    cout << ans % MOD;
}
int main(){
    freopen("employ.in",  "r", stdin);
    freopen("employ.out", "w", stdout);
    init();
    solve();
    print();
    return 0;
}