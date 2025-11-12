#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[507];
int id[507];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        id[i] = i;
    }
    int ans = 0;
     do {
        int fail = 0, pass = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == '0') {
                fail++;
            } else {
                if(fail >= c[id[i]]) {
                    ++fail;
                } else {
                    ++pass;
                }
            }
        }
        ans += (pass >= m);
    } while(next_permutation(id + 1, id + n + 1));
    cout << ans << '\n';
}
