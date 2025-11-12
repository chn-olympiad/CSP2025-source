#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q, pos, sum;
    cin >> n >> q;
    vector<pair<string, string>> dict(n);
    vector<pair<string, string>> ques(q);
    for (int i = 0; i < n; i++) {
        cin >> dict[i].first >> dict[i].second;
    }
    for (int i = 0; i < q; i++) {
        cin >> ques[i].first >> ques[i].second;
    }
    for (int i = 0; i < q; i++) {
        sum = 0;
        int minj = 1e9, maxj = -1e9;
        for (int j = 0; j < ques[i].first.size(); j++) {
            if (ques[i].first[j] != ques[i].second[j]) {
                minj = min(minj, j);
                maxj = max(maxj, j);
            }
        }
        // vector<bool> sign(n, false);
        for (int j = 0; j < n; j++) {
            if (dict[j].first.size() < maxj - minj) continue;
            // if (sign[j]) continue;
            pos = ques[i].first.find(dict[j].first);
            // if (pos != -1 && ques[i].second.substr(pos, dict[j].first.size()) == dict[j].second) {
            if (pos != -1 && ques[i].second == ques[i].first.substr(0, pos) + dict[j].second + ques[i].first.substr(pos + dict[j].second.size())) {
                sum++;
                // sign[j] = true;
                // cout << ques[i].first << " " << ques[i].second << " " << dict[j].first << " " << dict[j].second << endl;
            }
        }
        cout << sum << endl;
    }
    return 0;
}