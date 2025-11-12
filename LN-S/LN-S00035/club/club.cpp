#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return (a > b);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, s1 = 0, s2 = 0, sum = 0;
    int n, a1[10005], a2[10005], a3[10005];
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a1[i] >> a2[i] >> a3[i];
        }
        sort(a1 + 1, a1 + n + 1, cmp);
        sum = 0;
        for (int i = 1; i <= n / 2; i++) {
            sum += a1[i];
        }
        cout << sum;
    }
    return 0;
}
