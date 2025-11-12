#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
#ifndef LOCAL
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
#endif

    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);

    for(int i = 0; i < n * m; i++) {
        cin >> a[i];
    }

    int x = a[0];
    sort(a.begin(), a.end(), greater<int>());
    int p = (int)distance(a.begin(), find(a.begin(), a.end(), x));

    int c = (p / (2 * n)) * 2, r = -1;
    p %= (2 * n);
    if(p < n) {
        r = p;
    } else {
        c++, r = 2 * n - p - 1;
    }

    c++, r++;
    cout << c << ' ' << r << '\n';


    return 0;
}
// 8:47