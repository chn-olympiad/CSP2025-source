#include <bits/stdc++.h>
using namespace std;
int n, m, k;
unsigned long long tot = 0;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        tot += a;
    }
    cout << (unsigned)tot << endl;
    return 0;
}
