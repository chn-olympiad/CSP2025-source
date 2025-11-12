#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
string a[N], b[N];

int main() {
    //freopen("replace.in", "r", stdin);
    //freopen("replace.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    while (q--) {
        string x, y;
        cin >> x >> y;
        int cnt = 0, lenx = x.size(), leny = y.size(), flag = 0;
        for (int i = 1; i <= n; i++) {
            string st = "", ed = "";
            for (int j = 0; j < lenx; j++) {
                st += x[j];
                if (x[j] == a[i][0]) {
                    int len = 0;
                    while (len < a[i].size() && a[i][len] == x[j+len]) {
                        len++;
                    }
                    if (len == a[i].size()) {
                        flag = 1;
                        while (j + len < lenx) {
                            ed += x[j+len];
                            len++;
                        }
                        break;
                    }
                }
            }
            if (!flag) continue;
            string t = x;
            x = st + b[i] + ed;
            if (x == y) cnt++;
            x = t;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
