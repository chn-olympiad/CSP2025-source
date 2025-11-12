#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::string;

std::pair<string, string> stuple[200005];
int slen[200005];

string ques, replaced;
int n;
int solve() {
    if (ques.size() != replaced.size()) {
        return 0;
    }
    int sum = 0;
    size_t idx;
    for (int i = 0; i < n; ++i) {
        idx = ques.find(stuple[i].first);
        if (idx == string::npos) {
            continue;
        }
        size_t substr_len = slen[i];
        string ques_replaced = ques.substr(0, idx) + stuple[i].second + ques.substr(idx + substr_len);
        if (ques_replaced == replaced) {
            ++sum;
        }
    }
    return sum;
}

int q;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> stuple[i].first >> stuple[i].second;
        slen[i] = stuple[i].first.size();
    }
    while(q--) {
        cin >> ques >> replaced;
        cout << solve() << '\n';
    }
    return 0;
}
