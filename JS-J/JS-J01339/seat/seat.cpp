#include <bits/stdc++.h>
using namespace std;
long long n, m;
pair <long long, long long> a[110000];
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    long long sum = n * m;
    for (long long i = 1; i <= sum; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort (a + 1, a + sum + 1);
    long long ans;
    for (long long i = 1; i <= sum; i++) {
        if (a[i].second == 1) {
            ans = sum - i + 1;
            break;
        }
    }
    long long x, y;
    long long id = 0;
    for (long long i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            for (long long j = 1; j <= n; j++) {
                id++;
                if (id == ans)
                    x = j, y = i;
            }
        }
        else {
            for (long long j = n; j >= 1; j--) {
                id++;
                if (id == ans)
                    x = j, y = i;
            }
        }
    }
    cout << y << ' ' << x << '\n';
    return 0;
}
