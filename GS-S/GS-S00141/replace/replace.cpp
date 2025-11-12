#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, m1 = 1e9 + 7, m2 = 998244353;
ll n, q, ans;
pair<string, string> ss[N];
pair<string, string> t;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ss[i].first >> ss[i].second;
    }
    while (q--) {
        ans = 0;
        cin >> t.first >> t.second;
        ll len1 = t.first.size(), len2 = t.second.size();
        if (len1 != len2) {cout << 0 << '\n'; continue;}
        string com1 = "", com2 = ""; bool flag = 1, f2 = 1;
        for (int i = 0; i < len1; i++) {
            if (t.first[i] != t.second[i]) {
                if (flag) com1 += t.first[i], com2 += t.second[i];
                else {cout << 0 << '\n'; f2 = 0; break;}
            }
            else if (com1.size()) flag = 0;
        }
        if (!f2) continue;
        for (int i = 1; i <= n; i++) {
            ll p1 = 0, p2 = 0, l1 = 0, l2 = 0;
            while (l1 <= (int)com1.size() && l2 <= (int)ss[i].first.size()) {
                if (com1[l1] == ss[i].first[l2]) l2++;
                else l2 = 0;
                l1++;
            }
            while (p1 <= (int)com2.size() && p2 <= (int)ss[i].second.size()) {
                if (com2[p1] == ss[i].second[p2]) p2++;
                else p2 = 0;
                p1++;
            }
            if (p2 > ss[i].second.size() && l2 > ss[i].first.size()) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
