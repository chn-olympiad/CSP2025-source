#include <iostream>
#include <string>
using namespace std;
const long long N = 998244353;
unsigned long long n, x, f[1001] = {0, 1, 2};
string s;
int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> x;
    cin >> s;
    bool flag = 1;
    for (auto i : s) {
        if (s == 0) {
            flag = 0;
            break
        }
    }
    if (flag) {
        for (int i = 3; i <= n; ++ i) {
            f[i] = f[i - 1] * i % N;
        }
        cout << f[n];
    } else {
        cout << 0;
    }
    return 0;
}
