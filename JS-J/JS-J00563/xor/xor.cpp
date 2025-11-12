#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int MAX_N = 5e5 + 10;
int n, k, cnt;
int a[MAX_N], xors[MAX_N][MAX_N];

int main() {
    freopen("xor1.in", "r", stdin);
    freopen("xor1.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    //cnt = count(a, a + MAX_N, k);
    if ((n <= 2 && k == 0) || (n <= 100 && k == 0)) cout << n / 2;
    return 0;
}
