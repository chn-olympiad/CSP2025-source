#include<bits/stdc++.h>
using namespace std;

string s[200010][3];
string t1, t2;
int ans;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        cin >> s[i][1] >> s[i][2];
    while (q--) {
        ans = 0;
        cin >> t1 >> t2;
        for (int i = 1; i <= n; i++)
            if (t1.find(s[i][1]) != -1 && t2.find(s[i][2]) != -1 && t1.size() == t2.size()) {
                int x = t1.find(s[i][1]), y = s[i][1].size(), z = t1.size(), w = t2.find(s[i][2]);
                string tmp1 = t1.substr(0, x), tmp2 = t2.substr(0, x), tmp3 = t1.substr(x + y, z - (x + y) + 1), tmp4 = t2.substr(x + y, z - (x + y) + 1), tmp5 = t1.substr(x, y), tmp6 = t2.substr(x, y);
                if (tmp1 == tmp2 && tmp3 == tmp4)
                    ans++;
            }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
