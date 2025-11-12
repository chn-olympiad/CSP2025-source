# include <bits/stdc++.h>
# define endl "\n"
# define y1 fccmath
# define rei for (int i = 1; i <= n; ++i)
using namespace std;
const int mod = 998244353;
unsigned long long n, m, ans=1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    //n = 100;
    int tmp = n;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if (!k) {
            tmp--;
        }
    }
    for (int i = 1; i <= tmp; ++i) {
        ans %= mod;
        ans *= i;
    }
    cout << ans;
    return 0;
}
