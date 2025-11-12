#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    int n, m, j;
    cin >> n >> m;
    vector<int> a;
    for (int i = 1; i <= n * m; i++) {
        int s;
        cin >> s;
        if (i == 1) j = s;
        a.push_back(s);
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == j) {
            cout << i / n + 1 << " ";
            int s = i % n;
            if ((i / n + 1) % 2 == 0) {
                cout << n - s;
            } else {
                cout << 1 + s;
            }
            return 0;
        }
    }
    return 0;
}
