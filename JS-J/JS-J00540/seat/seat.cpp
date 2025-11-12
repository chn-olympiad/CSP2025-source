#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, score, id;
    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << "1 1";
        return 0;
    }
    int a[n * m + 1];
    memset(a, 0, sizeof(a));
    cin >> a[1];
    score = a[1];
    for(int i = 2; i <= n * m; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++) {
        if(a[i] == score) {
            id = i;
            break;
        }
    }
    int h = id / m + int(id % m != 0), s = id % (2 * m);
    if(s > m) {
        int q = (h - 1) * n;
        for(int i = n; i >= 1; i--) {
            q++;
            if(q == id) {
                cout << h << ' ' << i;
            }
        }
    } else {
        cout << h << ' ' << s;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
