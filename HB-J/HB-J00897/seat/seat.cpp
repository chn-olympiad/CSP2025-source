#include <bits/stdc++.h>
using namespace std;
int n, m, mp[11][11], ans_x = INT_MIN, ans_y = INT_MIN, x = 1, y = 1, p = 1;
bool flag = true; // true -> down, false -> up;
struct seat {
    int id, score; // id -> no_sort_i;
} a[121]; // struct version
// vector<seat> a(121);
bool cmp(seat x, seat y) {
    return x.score > y.score;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i].score;
        a[i].id = i;
    }
    int found = a[1].score;
    sort(a + 1, a + n * m + 1, cmp);
    // sort(a.begin(), a.end(), cmp);
    while (/*x <= n && y <= m &&*/ p <= n * m) { // x -> hang, y -> lie, n hang m lie
        // mp[x][y] = a[p].score;
        // walk();
        if (x == n && y == m) break; // last
        /* x -> hang, y -> lie
        x-1,y-1 x-1,y x-1,y+1
         x,y-1   x,y   x,y+1
        x+1,y-1 x+1,y x+1,y+1
        */
        if (x == n) {
            // zuihouyihang
            mp[x][y] = a[p++].score;
            y++;
            mp[x][y] = a[p++].score;
            flag = false; // up
            x--;
        }
        if (x == 1 && p != 1) {
            // dyh
            mp[x][y] = a[p++].score;
            y++;
            mp[x][y] = a[p++].score;
            flag = true; // down
            x++;
        }
        if (y == 1 || y == m) {
            // first & last lie
            mp[x][y] = a[p++].score;
            x++; // xiayihang
        }
        // (a[p].id == 1) { // a[p].id == 1
            //ans_x = x, ans_y = y;
            //break;
        //} // if (mp[x][y] == found) ans_x = x, ans_y = y;
    }
    int ans_x2 = INT_MIN, ans_y2 = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == found) {
                ans_x2 = i, ans_y2 = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << ans_x2<< ' ' << ans_y2;
    return 0;
}
