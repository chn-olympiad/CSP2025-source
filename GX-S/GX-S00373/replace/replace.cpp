#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
struct node {
    string a, b;
}s[maxn];
int n, q_;

string SubStr(string inp, int idxx, int len) {
    string newS;
    for (int i = idxx; i < idxx + len; i ++)
        newS += inp[i];
    return newS;
}

string RplStr(string Target, string inp, int idxx) {
    int ptr = 0;
    for (int i = idxx; i < idxx + inp.length(); i ++)
        Target[i] = inp[ptr], ptr ++;
    return Target;
}

void solveBF() {
    for (int i = 1; i <= n; i ++)
        cin >> s[i].a >> s[i].b;
    while(q_ --) {
        string t1, t2; cin >> t1 >> t2;
        int cnt = 0;
        for (int i = 1; i <= n; i ++) { // for each s_i
            int len = s[i].a.length();
            for (int j = 0; j + len <= t1.length(); j ++) {
                // for each char in t1 as a start
                if (SubStr(t1, j, len) == s[i].a) {
                    // valid to replace
                    string R = RplStr(t1, s[i].b, j);
                    if (R == t2) {
                        
                        // cout << "s1:" << s[i].a << '\n';
                        // cout << "s2:" << s[i].b << '\n';
                        // cout << "t1:" << t1 << '\n';
                        // cout << "t2:" << t2 << '\n';
                        // cout << "R:" << R << '\n';

                        cnt ++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

}

void solveSub() {
    pair<int, int> q[n + 3][3];
    vector<int> offs(n + 3);
    for (int i = 1; i <= n; i ++) {
        string s1, s2; cin >> s1 >> s2;
        int pos1, pos2;
        for (int j = 0; j < s1.length(); j ++) {
            if (s1[j] == 'b') q[i][1].first = j, q[i][1].second = s1.length() - j - 1, pos1 = j;
            if (s2[j] == 'b') q[i][2].first = j, q[i][2].second = s1.length() - j - 1, pos2 = j;
        }
        offs[i] = pos1 - pos2;
    }
    while(q_ --) {
        string t1, t2; cin >> t1 >> t2;
        int pos1, pos2;
        for (int i = 0; i < t1.length(); i ++) {
            if (t1[i] == 'b') pos1 = i;
            if (t2[i] == 'b') pos2 = i;
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            if (offs[i] == pos1 - pos2) {
                if (q[i][1].first <= pos1 && pos1 + q[i][1].second < t1.length())
                    ans ++;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q_;
    if (n <= 1000 && q_ <= 1000)
        solveBF();
    else
        solveSub();
    return 0;
}