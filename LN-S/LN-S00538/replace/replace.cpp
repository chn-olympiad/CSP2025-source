#include <bits/stdc++.h>
using namespace std;
map <string, string> mp;
int n, q, maxlen = -1;
int main () {
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s_1, s_2;
        cin >> s_1 >> s_2;
        mp[s_1] = s_2;
        int len = s_1.size () ;
        maxlen = max (maxlen, len) ;
    }
    while (q--) {
        string s1, s2, sx = "", sy = "";
        int ans = 0;
        cin >> s1 >> s2;
        int g = 0, x, y;
        while (s1[g] == s2[g]) g++;
        x = g;
        g = s1.size () - 1;
        while (s1[g] == s2[g]) g--;
        y = g;
        for (int i = x; i <= y; i++) {
            sx += s1[i];
            sy += s2[i];
        }
        string sx1 = sx, sy1 = sy;
        if (mp[sx1] == sy1) ans++;
        //cout << sx1 << " " << sy1 << " " << ans << "\n" ;
        for (int i = x - 1; i >= 0; i--) {
            if (sx1.size () > maxlen) break;
            sx1 = s1[i] + sx1 ;
            sy1 = s2[i] + sy1 ;
            if (mp[sx1] == sy1) ans++;
            //cout << sx1 << " " << sy1 << " " << ans << "\n" ;
            for (int j = y + 1; j < s1.size(); j++) {
                sx1 = sx1 + s1[j] ;
                sy1 = sy1 + s2[j] ;
                if (mp[sx1] == sy1) ans++;
                //cout << sx1 << " " << sy1 << " " << ans << "\n" ;
            }
        }
        cout << ans << "\n" ;
    }
}