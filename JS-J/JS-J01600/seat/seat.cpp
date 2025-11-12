#include <bits/stdc++.h>
using namespace std;
//seat

int s[101];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> s[i];
    }
    int sc = s[1];
    sort(s + 1, s + 1 + n * m, [](int a, int b) {  return a > b;});
    int c = lower_bound(s + 1, s + 1 + n * m, sc, [](int a, int b) {  return a > b;}) - s;
    int shang = c / n;
    int yu = c % n;
    if (yu == 0) {
        cout << shang << " " << 1;
    }
    else {
        cout << shang + 1 << " ";
        int cc = shang + 1; //?? Wo ying yu bu hao.
        if (cc & 1) {
            cout << yu;
        }
        else {
            cout << n - yu + 1;
        }
    }
}
