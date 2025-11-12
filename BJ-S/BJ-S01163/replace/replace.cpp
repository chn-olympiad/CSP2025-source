#include <iostream>
using namespace std;

const int NR = 2e5 + 5;
string s1[NR], s2[NR];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }

    string t1, t2;
    int ans, cl, cr, flg;
    while (q--) {
        cin >> t1 >> t2;
        
        if (t1.size() != t2.size()) {
            puts("0");
            continue;
        }

        for (int i = 0;i < t1.size(); i++)
            if (t1[i] != t2[i]) {
                cl = i;
                break;
            }
        for (int i = t1.size() - 1; i >= 0; i--)
            if (t1[i] != t2[i]) {
                cr = i;
                break;
            }
        

        ans = 0;
        for (int i = 0; i <= cl; i++) {
            for (int j = 1; j <= n; j++) {
                if (i + s1[j].size() <= cr) continue;
                flg = 1;
                for (int k = 0; k < s1[j].size(); k++) {
                    if (s1[j][k] != t1[i + k] || s2[j][k] != t2[i + k]) {
                        flg = 0;
                        break;
                    }
                }
                if (flg) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}