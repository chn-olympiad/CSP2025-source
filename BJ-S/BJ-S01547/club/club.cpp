#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5 + 50;

int t, n, a[maxn][10], b[maxn][10];
priority_queue<int> qa;
priority_queue<int> qb;
priority_queue<int> qc;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            sort(a[i] + 1, a[i] + n + 1, cmp);
            for (int j = 1; j <= 3; j++) {
                if (b[i][j] == a[i][1]) {
                    if (j == 1) {
                        qa.push(-b[i][j]);
                        if (qa.size() > n / 2) qa.pop();
                    }
                    else if (j == 2) {
                        qb.push(-b[i][j]);
                        if (qb.size() > n / 2) qb.pop();
                    }
                    else if (j == 3) {
                        qc.push(-b[i][j]);
                        if (qc.size() > n / 2) qc.pop();
                    }
                    break;
                }
            }
        }
        int ans = 0;
        while (qa.size()) {
            ans += -qa.top();
            qa.pop();
        }
        while (qb.size()) {
            ans += -qb.top();
            qb.pop();
        }
        while (qc.size()) {
            ans += -qc.top();
            qc.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
