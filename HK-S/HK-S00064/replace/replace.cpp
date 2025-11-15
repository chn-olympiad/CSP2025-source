#include <bits/stdc++.h>
using namespace std;

fstream fin("replace.in");
ofstream fout("replace.out");

bool chk_B_str(string s) {
    int n = s.size(), a = 0, b = 0;
    for (char c : s) {
        if (c == 'a') {
            ++a;
        } else if (c == 'b') {
            ++b;
        } else {
            return false;
        }
    }
    return (a == n - 1 && b == 1);
}

bool chk_B(vector<pair<string, string>>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (!chk_B_str(a[i].first) || !chk_B_str(a[i].second)) {
            return false;
        }
    }
    return true;
}

int index(string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b') {
            return i;
        }
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    fin >> n >> m;

    vector<pair<string, string>> repl(n), queries(m);
    for (int i = 0; i < n; ++i) {
        fin >> repl[i].first >> repl[i].second;
    }
    for (int i = 0; i < m; ++i) {
        fin >> queries[i].first >> queries[i].second;
    }

    // i hope this works for subtest 6
    if (m == 1 && chk_B(repl) && chk_B(queries)) {
        vector<int> left(n), right(n), offsets(n);
        for (int i = 0; i < n; ++i) {
            string rs = repl[i].first, rt = repl[i].second;
            offsets[i] = index(rt) - index(rs);
            left[i] = index(rs);
            right[i] = n - index(rs) - 1;
        }

        string qs = queries[0].first, qt = queries[0].second;
        int offset = index(qt) - index(qs);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int qleft = index(qs), qright = n - index(qs) - 1;
            if (qleft >= left[i] && qright >= right[i] && offsets[i] == index(qt) - index(qs)) {
                ++ans;
            }
        }

        fout << ans << '\n';
        return 0;
    }

    map<string, string> dict;
    for (int i = 0; i < n; ++i) {
        dict[repl[i].first] = repl[i].second;
    }

    // bruteforce
    for (int i = 0; i < m; ++i) {
        string qs = queries[i].first, qt = queries[i].second;
        int ans = 0;
        for (int l = 0; l < qs.size(); ++l) {
            for (int r = l; r < qs.size(); ++r) {
                string s = "";
                for (int k = l; k <= r; ++k) {
                    s += qs[k];
                }
                if (dict.find(s) != dict.end()) {
                    string qs_copy = qs;
                    for (int kk = l; kk <= r; ++kk) {
                        qs_copy[kk] = dict[s][kk - l];
                    }
                    if (qs_copy == qt) {
                        ++ans;
                    }
                }
            }
        }
        fout << ans << '\n';
    }
}