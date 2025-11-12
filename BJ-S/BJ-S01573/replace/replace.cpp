#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, q;
string s1[MAXN], s2[MAXN];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> s1[i] >> s2[i];
    }
    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = t1 == t2;
        for(int i = 0; i < t1.size(); ++i) {
            for(int j = i + 1; j < t1.size(); ++j) {
                string tmp1 = "", tmp2 = "", tmp3 = "";
                for(int k = 0; k < i; ++k) tmp1 += t1[k];
                for(int k = i; k <= j; ++k) tmp2 += t1[k];
                for(int k = j + 1; k < t1.size(); ++k) tmp3 += t1[k];
                for(int k = 1; k <= n; ++k) {
                    if(tmp2 == s1[k]) {
                        if(tmp1 + s2[k] + tmp3 == t2) ++ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
