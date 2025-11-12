#include <bits/stdc++.h>
using namespace std;
int n, m, c = 1, r = 1, f = 1;
struct Stu {
    int a, i;
} stu[105];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> stu[i].a;
        stu[i].i = i;
    }
    sort(stu + 1, stu + 1 + n * m, [](Stu l, Stu r) {
       return l.a > r.a;
    });
    //for (int i = 1; i <= n * m; i++) {
        //cout << stu[i].a << ' ' << stu[i].i << '\n';
    //}
    int i = 1;
    while (stu[i].i != 1) {
        if (f > 0) {
            if (r != n) {
                r += f;
            } else {
                c++;
                f = 0 - f;
            }
        } else {
            if (r != 1) {
                r += f;
            } else {
                c++;
                f = 0 - f;
            }
        }
        i++;
    }
    cout << c << ' ' << r;
    cout << '\n';
    return 0;
}
