#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;

char s[N];
int c[N], ord[N], realc[N];
int ans;

bool verify() {
    int hired = 0;
    for(int i = 1; i <= n; i++) {
        realc[i] = c[ord[i]];
    }
    for(int i = 1; i <= n; i++) {
        if(i - 1 - hired >= realc[i]) continue;
        if(s[i] == '0') continue;
        hired++;
    }
    return hired >= m;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s + 1;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) ord[i] = i;
    do {
        if(verify()) ans++;
        if(ans >= 998244353) ans -= 998244353;
    } while(next_permutation(ord + 1, ord + n + 1));
    cout << ans << endl;
    return 0;
}
