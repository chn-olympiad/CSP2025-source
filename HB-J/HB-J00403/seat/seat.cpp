#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int score[MAXN];
int R_S, ans;
int n, m;
int h = 0, l = 1;

bool cmp(int a, int b) {
    return a > b;
}

int main () {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> score[i];
    }
    R_S = score[0];
    sort(score, score + n * m - 1, cmp);
    for (int i = 0; i < n * m; i++) {
        if (score[i] == R_S) {
            ans = i + 1;
        }
    }
    while (1) {
        if (ans - n > 0) {
            ans -= n;
            l++;
        } else {
            if (l % 2 != 0) {
                h += ans;
            } else {
                h = n - ans + 1;
            }
            break;
        }
    }
    cout << l << " " << h;
    return 0;
}
