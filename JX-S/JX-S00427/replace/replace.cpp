#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, q;
string s1[N], s2[N];


int f(string t1, string t2, string t3, string t4) {
    int l = 0, r = t3.size() - 1, ans = 0;
    while (r < t1.size()) {
        string k = t1.substr(l, t3.size());
        if (k == t3) {
            string temp = t1.replace(l, t4.size(), t4);
            if (temp == t2) {
                ans++;
                //cout << temp << ' ' << t1 << '\n';
            }
        }
        l++;
        r++;
    }
    return ans;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }

    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += f(t1, t2, s1[i], s2[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
