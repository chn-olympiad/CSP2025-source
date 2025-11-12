#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int n, m, c[501], mod = 998244353, b[501];
bool flag = true;
string s;
int njc(int x) {
    int ans = 1;
    for (int i = 2; i <= x; i++) {
        ans = ans * i % mod;
    }
    return ans;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (char i : s) {
        if (i == '0') {
            flag = false;
        }
    }
    if (flag) {
        cout << njc(n);
    } else {
        int ddd = 0;
        for (int i = 1; i <= n; i++) {
            b[i] = i;
        }
        do {
            int nc = 0, ans = 0;
            for (int i = 1; i <= n; i++) {
                if (c[b[i]] <= nc) {
                    nc++;
                } else if (s[b[i] - 1] == 1) {
                    ans++;
                } else {
                    nc++;
                }
            }
            cout << ans << endl;
            if (ans >= m) {
                ddd++;
            }
        } while (next_permutation(b + 1, b + n + 1));
        cout << ddd;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

