#include <bits/stdc++.h>
using namespace std;

int n, q;
map<pair<string, string>, int> ds;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string s1, s2; cin >> s1 >> s2;

        ds[{s1, s2}]++;
    }

    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;

        long long ans = 0;
        if(t1.size() == t2.size()) {
            int n = t1.size();

            int qlt = 0;
            for(int i = n - 1; i >= 0; i--) {
                if(t1[i] != t2[i]) {
                    qlt = i;
                    break;
                }
            }

            string s1, s2;
            string q1 = "", q2 = "";
            for(int i = 0; i < n; i++) {
                if(q1 != q2) break;
                s1 = "", s2 = "";

                for(int j = i; j < n; j++) {
                    s1 += t1[j], s2 += t2[j];
                    if(j >= qlt) ans += ds[{s1, s2}];
                }
                q1 += t1[i], q2 += t2[i];
            }
        }

        cout << ans << '\n';
    }
}  