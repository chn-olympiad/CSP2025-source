#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t;
int n;
int a[N][3];
// long long s = 0;

int sz1, sz2, sz3;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        priority_queue<int, vector<int>, greater<int> > mp1, mp2, mp3;
        sz1 = sz2 = sz3 = 0;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
                sz1++;
                sum += a[i][0];
                mp1.push(a[i][0] - max(a[i][1], a[i][2]));
                if (sz1 > n/2) {
                    int x = mp1.top(); mp1.pop();
                    sum -= x;
                    sz1--;
                    // mp1.pop();
                }
            } else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
                sz2++;
                sum += a[i][1];
                // cout << "push" << a[i][1] << '\n';
                mp2.push(a[i][1] - max(a[i][0], a[i][2]));
                if (sz2 > n/2) {
                    int x = mp2.top(); mp2.pop();
                    // cout << "erase" << x << '\n';
                    sum -= x;
                    sz2 --;
                    // mp2.pop();
                }
            } else if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) {
                sz3++;
                sum += a[i][2];
                mp3.push(a[i][2] - max(a[i][0], a[i][1]));

                if (sz3 > n/2) {
                    int x = mp3.top(); mp3.pop();
                    sum -= x;
                    sz3--;
                    // mp3.pop();
                }
            }
            // cout << sz2 << ' ' << sum << '\n';
        }
        cout << sum << '\n';
    }

    return 0;
}