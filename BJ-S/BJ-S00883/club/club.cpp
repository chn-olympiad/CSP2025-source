#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define int long long

using namespace std;

const int N = 1e5 +10;

int T, n;
int a[N][5];
priority_queue <int , vector <int>, greater <int> > q1, q2, q3;

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie (0);
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);

    cin >> T;
    while (T -- ) {
        int ans = 0, c1 = 0, c2 = 0, c3 = 0;
        while (q1.size()) q1.pop ();
        while (q2.size()) q2.pop ();
        while (q3.size()) q3.pop ();

        cin >> n;
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][1] >= max (a[i][2], a[i][3])) {
                ans += a[i][1], c1 ++ ;
                q1.push (a[i][1] - max (a[i][2], a[i][3]));
            }
            else if (a[i][2] >= max (a[i][1], a[i][3])) {
                ans += a[i][2], c2 ++ ;
                q2.push (a[i][2] - max (a[i][1], a[i][3]));
            }
            else if (a[i][3] >= max (a[i][1], a[i][2])) {
                ans += a[i][3], c3 ++ ;
                q3.push (a[i][3] - max (a[i][1],a[i][2]));
            }
        }

        while (c1 > n / 2) {
            ans -= q1.top ();
            q1.pop ();
            c1 -- ;
        }

        while (c2 > n / 2) {
            ans -= q2.top ();
            q2.pop ();
            c2 -- ;
        }
        while (c3 > n / 2) {
            ans -= q3.top ();
            q3.pop();
            c3 -- ;
        }

        cout << ans <<endl;
    }

    return 0;
}
