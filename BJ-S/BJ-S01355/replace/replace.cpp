#include <bits/stdc++.h>

using namespace std;

map<string, string> mp;

int main () {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);


    int n, q;
    cin >> n >> q;
    int ans = 0;



    for (int i = 1; i <= n; i ++) {
        string a, b;
        cin >> a >> b;

        mp[a] = b;
    }

    while (q --) {
        ans = 0;
        string s, x;
        cin >> s >> x;
        x = " " + x;

        int len = s.size();
        s = " " +s;

        for (int i = 1; i <= len; i ++) {
            for(auto p : mp) {
                string s1 = p.first;
                string s2 = p.second;

//                cout << s1 << endl;

                if (n - i > s1.size()) continue;

                if (s.substr(i, s1.size()) == s1 && x.substr(i, s1.size()) == s2) {
                    ans ++;
                }
            }
        }
        cout << ans <<endl;
    }



    return 0;
}
