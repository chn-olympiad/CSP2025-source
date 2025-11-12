#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 10 + 5;
int n, m;
int total = 0;
vector<int> sts[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    total = n * m;
    vector<int> a(total);
    cin >> a[0];
    int littler = a[0];
    for (int i = 1; i < total; i ++) {
        cin >> a[i];
    }
    int nw = 0;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            sts[i].push_back(a[nw]);
            nw ++;
        }
    }
    for (int i = 1; i < m; i += 2) {
        reverse(sts[i].begin(), sts[i].end());
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (sts[i][j] == littler) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }
    return 0;
}
