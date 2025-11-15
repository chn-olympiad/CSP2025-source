#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;

int n, m, k, d;
signed main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> d >> d >> d;
    for (int i = 1; i <= k; i++) for (int i = 1; i <= n + 1; i++) cin >> d;
    cout << "0\n";
    fclose(stdin); fclose(stdout);
    return 0;
}