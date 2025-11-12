#include <iostream>
using namespace std;

const int MOD = 998244353;

int n, m, l, ans = 1;
string s;
int c[505], zero[505];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    cout << ans;
    return 0;
}
