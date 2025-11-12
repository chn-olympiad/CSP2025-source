#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];

bool cmp(int n, int m) {
    return n > m;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++) cin >> a[i];
    int grade = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int id;
    for (int i = 1; i <= n * m; i ++)
        if (a[i] == grade) {
            id = i;
            break;
        }
    int line = 0;
    if (id % n != 0) line ++;
    line += id / n;
    cout << line << " ";
    id -= (line - 1) * n;
    if (line % 2 == 1) cout << id << endl;
    else cout << n - id + 1 << endl;
    return 0;
}
