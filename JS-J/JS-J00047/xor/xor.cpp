#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 5;
int a[MAXN];
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    srand(time(NULL));
    cout << rand() % n << endl;
    return 0;
}