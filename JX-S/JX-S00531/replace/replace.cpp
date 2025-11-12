//RP++ tiao le 90 min jie guo da shu ju guo bu liao hai neng you fen ma?
//sto CCF orz qiu
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int n, q;
string c[N][3];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i][1] >> c[i][2];
        c[i][1] = '&' + c[i][1];
        c[i][2] = '&' + c[i][2];
    }
    for (int i = 1; i <= q; ++i) {
        int ans = 0;
        string t[3];
        cin >> t[1] >> t[2];
        t[1] = '&' + t[1]; t[2] = '&' + t[2];
        for (int j = 1; j <= n; ++j) {
            int len1 = t[1].size() - 1, len2 = c[j][1].size() - 1;
            if (len1 < len2) continue;
            int l = 0, pos = 0, idx = 0, aaa = 0, cnt = 0;
            for (int k = 1; k <= len1; ++k) {
                if (t[1][k] == c[j][1][l + 1]) {
                    l++;
                } else  {
                    aaa = 1;
                    pos = max(pos, l);
                    l = 0;
                }
      //          printf("%d %d\n", l, pos);
            }
            l = 0;
            if (aaa == 0) pos = len1, idx = 1;
            for (int k = 1; k <= len1; ++k) {
               if (t[1][k] == c[j][1][l + 1]) l++;
               else {
                    if (l == pos) {
                        idx = k - l;
                        break;
                    } else
                    l = 0;
               }
            }
       //     printf("%d %d\n", idx, pos);
        //    printf("\n");
            int ll = 0;
            string cc = t[1];
            if (pos == len2) {
                for (int k = idx; k < idx + pos; ++k)
                    cc[k] = c[j][2][++ll];
            //    cout << t[1] << c[j][2] << '\n';
                if (cc == t[2]) ans++;
            }
        //    printf("%d %d\n", len1, len2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
