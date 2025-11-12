#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, q;
int sz[N];
string s1[N], s2[N];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i ++ ) {
        cin >> s1[i] >> s2[i];
        sz[i] = s1[i].size();
    }

    while (q -- ) {
        string a, b;
        cin >> a >> b;

        long long res = 0;
        m = a.size();
        if (a == b) {
            for (int i = 1; i <= n; i ++ )
                if (sz[i] == m && s2[i] == b) res ++ ;
        } else {
            int st = 0, ed = m - 1;
            while (a[st] == b[st]) st ++ ;
            while (a[ed] == b[ed]) ed -- ;
            int len = ed - st + 1;
            for (int i = 1; i <= n; i ++ ) {
                if (len <= sz[i]) {
                    int dif = sz[i] - len;
                    for (int j = max(0, st - dif); j <= st + dif; j ++ ) {
                        if (j + len > m) continue;
                        if (a.substr(j, sz[i]) == s1[i] && b.substr(j, sz[i]) == s2[i]) res ++ ;
                    }
                }
            }
        }
        printf("%lld\n", res);
    }
    
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/