#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> v(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> v[i];
        if (v[i] > v[0]) cnt++;
    }
    cout << cnt / n + 1 << ' ' << (((cnt / n) & 1) ? n - cnt % n : cnt % n + 1) << '\n';
    return 0;
}