#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
pair<string, string> dic[N];

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        dic[i] = {s1, s2};
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            int idx = t1.find(dic[i].first);
            while (idx != t1.npos) {
                if (t1.substr(0, idx) + dic[i].second + t1.substr(idx + dic[i].second.size()) == t2) ret++;
                idx = t1.find(dic[i].first, idx + 1);
            }
        }
        cout << ret << "\n";
    }
	return 0;
}
