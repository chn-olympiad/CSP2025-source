#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, s[N], c[N], p[N], ans;
int main() {
    freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    string str; cin >> str; for(int i = 1; i <= n; i++) s[i] = str[i-1] - '0';
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++) p[i] = i;
    do {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(cnt >= c[p[i]]) cnt++;
            else cnt += !s[i];
        }
        if(n - cnt >= m) ans++;
    } while(next_permutation(p + 1, p + n + 1)) ;
    printf("%d\n", ans);
    return 0;
}