#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505, mod = 998244353;
int p[N], s[N], c[N];
int n, m;

void work1() {
    iota(p+1, p+1+n, 1);
    int ans = 0;
    do {
        int t = 0, no = 0;
        for (int i = 1; i <= n; i++) {
            if (no >= c[p[i]])
                no++;
            else
                t += s[i], no += s[i]^1;
        }
        if (t >= m) ans++;
    } while (next_permutation(p+1, p+1+n));
    cout << ans << endl;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        s[i] = ch-'0';
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    if (n <= 10)
        work1();
    return 0;
}