#include <bits/stdc++.h>
using namespace std;

const int maxnq = 2e5 + 5;

string s[maxnq][5];

bool isit(int b, int end, string is, string it) {
    for (int i = b; i <= end; i++) {
        if (it[i] != is[i - b]) {
            return 0;
        }
    }
    return 1;
}
bool ok(int a, int b) {
    return (a + 1) < (b + 1);
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][1] >> s[i][2];
    }
    for (int j = 1; j <= q; j++) {
        string tj1, tj2;
        string _Origin = tj1;
        cin >> tj1 >> tj2;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int k = -1; ok(k, tj1.size()); k++) {
                if (isit(k + 1, k + s[i][1].size(), s[i][1], tj1)) {
                    for (int f = k + 1; f <= (k + s[i][1].size()); f++) {
                        tj1[f] = s[i][2][f - (k + 1)];
                    }
                    if (tj1 == tj2) {
                        tj1 = _Origin;
                        flag = true;
                        cnt++;
                        break;
                    }
                    else tj1 = _Origin;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0; 
}