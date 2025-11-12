#include <bits/stdc++.h>
using namespace std;
#define inlfc __attribute__((always_inline))
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

struct ACAM {
    int n = 0;
    vector<map<char, int>> T;
    vector<vector<int>> output;
    vector<int> fail, tag;
    inlfc ACAM() {
        T.push_back(map<char, int>());
        fail.push_back(0);
        tag.push_back(0);
        output.push_back(vector<int>());
    }
    inlfc void newNode(int x, int c) {
        T[x][c] = ++ n;
        T.push_back(map<char, int>());
        fail.push_back(0);
        tag.push_back(0);
        output.push_back(vector<int>());
    }
    inlfc void insert(string s) {
        int x = 0;
        for (auto c : s) {
            if (!T[x].count(c)) {
                newNode(x, c);
            }
            x = T[x][c];
        }
        tag[x] ++;
    }
    inlfc void build() {

    }
};

string t[MAXN][2];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> t[i][0] >> t[i][1];
    }
    if (n + q <= 200) {
        for (int i = 1; i <= q; i ++) {
            int ans = 0;
            string s, s2;
            cin >> s >> s2;
            for (int j = 1; j <= n; j ++) {
                for (int k = 0; k <= s.size() && k + t[j][1].size() < s.size(); k ++) {
                    string x = s.substr(k, t[j][0].size()),
                           y = s2.substr(k, t[j][1].size());
                    if (x == t[j][0] && y == t[j][1]
                        && s.substr(0, k) == s2.substr(0, k)
                        && s.substr(k + t[j][0].size()) == s2.substr(k + t[j][1].size())) ans ++;
                }
            }
            cout << ans << '\n';
        }
    } else {
        for (int i = 1; i <= q; i ++) {
            int ans = 0;
            string s, s2;
            cin >> s >> s2;

            cout << 0 << '\n';
        }
    }
    return 0;
}
