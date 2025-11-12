#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int sit[15][15];
    int s;
    vector<int> score;
    int r1; // r's score
    int pos = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cin >> s;
            if (i == 1 && j == 1) {
                r1 = s;
            }
            else {
                if (s > r1) {
                    pos ++;
                }
            }
            score.push_back(s);
        }
    }
    sort(score.begin(), score.end(), cmp);
    double c, r;
    c = ceil((double) pos / n);
    if ((int) c % 2 == 1) {
        r = pos - (c - 1) * n;
    }
    else {
        r = c * n + 1 - pos;
    }
    cout << c << " " << r;
    return 0;
}
