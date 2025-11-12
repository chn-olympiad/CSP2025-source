#include <iostream>

using namespace std;
const int MAXN = 5e5 + 5;
long long n, k;
long long a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cout << n << '\n';
    return 0;
}
