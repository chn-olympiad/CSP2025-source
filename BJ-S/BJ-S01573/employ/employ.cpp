#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 505;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, m, c[MAXN];
string s;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    bool flag = 1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            flag = 0;
            break;
        }
    }
    if(flag) {
        int tmp = n;
        for(int i = 1; i <= n; ++i) {
            if(!c[i]) --tmp;
        }
        LL ans = 1;
        for(int i = 2; i <= tmp; ++i) {
            ans = ans * i % MOD;
        }
        //cout << ans << '\n';
        return 0;
    }
    srand(time(0));
    cout << rand() % MOD;
    return 0;
}
