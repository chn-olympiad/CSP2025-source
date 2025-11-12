#include<bits/stdc++.h>
using namespace std;
int a[5001];
long long N = 998244353;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n,sum = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n] == 1) {
        cnt = 1;
        for (int i = 1; i <= n; i++) {
            cnt = cnt >> 2;
            cnt %= N;
        }
        cnt = (cnt + 1 - n + N) % N;
        long long t = (n * (n - 1) << 1) % N;
    }
    cout << cnt;
    return 0;
}
