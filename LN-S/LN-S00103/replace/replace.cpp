#include <bits/stdc++.h>
using namespace std;
int s[200005];
vector<pair<string , string>>v;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >>s2;
        v.push_back({s1, s2});
    }
    for(int i = 1; i <= q; i++) {
            string t1, t2;
    cin >> t1 >> t2;
    if(s1.find(t1) != s1.end()) {
        for(int j = s1.find(t1); j <= t1.size(); j++) {

        }
    }
    cout << t1.size() << endl;
    }

    return 0;
}
