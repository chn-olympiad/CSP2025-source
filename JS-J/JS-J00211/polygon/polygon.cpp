#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n = 0;
int a[5005] = {};
int cnt = 0;
void f(int i, int maxN, int sum, int num) {
    if (num >= 3 && sum > maxN * 2)
        ++cnt;
    if (i == n)
        return;
    cnt %= 998244353;
    f(i + 1, max(maxN, a[i + 1]), sum + a[i + 1], num + 1);
    f(i + 1, maxN, sum, num);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    f(1, a[1], a[1], 1);
    f(0, 0, 0, 0);
    cout << cnt;
    return 0;
}
