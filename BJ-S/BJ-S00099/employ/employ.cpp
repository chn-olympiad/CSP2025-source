#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, m, ans;
string s;
int c[505], num[505];

int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        num[i] = i;
    }
    do {
        int fq = 0;
        for (int i = 1; i <= n; ++i) {
            if (c[num[i]] <= fq || s[i - 1] == '0') {
                fq++;
                continue;
            }
        }
        if (n - fq >= m) {
            ans++;
        }
    } while (next_permutation(num + 1, num + n +1));
    cout << ans;
    return 0;
}
