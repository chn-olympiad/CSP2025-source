#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, q;

string s[2][N];

int idx[2][2][N];

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            cin >> s[j][i];
            int flag = 0;
            for (int k = 0; k < s[j][i].size(); k++) {
                if (s[j][i][k] == 'b') flag = 1;
                else idx[flag][j][i]++;
            }
        }
    }

    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int tmp = 0;
        bool flag = 0;
        int idx1 = 0, idx2 = 0;
        for (int i = 0; i < t1.size(); i++) {
            if (t1[i] == 'b') {
                if (t2[i] != 'b') {
                    flag = 1;
                    puts("0");
                    break;
                }
                tmp = 1;
            } else {
                if (!tmp) idx1++;
                else idx2++;
            }
            
        }
        if (flag) continue;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (idx1 >= idx[0][0][i] && idx2 >= idx[1][0][i]) ans++;
        }
        printf("%lld\n", ans);
    }

    fclose(stdin);
    fclose(stdout); 
    return 0;  
}