// 50 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr int BASE = 2333, N = 5e6;

u64 base[N + 1];

void prepare()
{
    base[0] = 1;

    for (int i = 1; i <= N; ++i)
        base[i] = base[i - 1] * BASE;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    prepare();

    vector<pair<string, string>> s(n);
    vector<pair<u64, u64>> hsh(n);
    vector<int> diff(n), len(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i].first >> s[i].second;
        diff[i] = len[i] = s[i].first.size();

        for (int j = 0; j < len[i]; ++j) {
            if (s[i].first[j] != s[i].second[j]) {
                diff[i] = j;
                break;
            }
        }

        for (int j = 0; j < len[i]; ++j) {
            hsh[i].first += base[j] * s[i].first[j];
            hsh[i].second += base[j] * s[i].second[j];
        }
    }

    while (q-- > 0) {
        string t1, t2;
        cin >> t1 >> t2;

        int m = t1.size(), idx = m;

        if (m != t2.size()) {
            cout << "0\n";
            continue;
        }

        for (int i = 0; i < m; ++i) {
            if (t1[i] != t2[i]) {
                idx = i;
                break;
            }
        }

        if (idx == m) {
            cout << n << '\n';
            continue;
        }

        vector<u64> hsh1(m), hsh2(m);

        for (int i = 0; i < m; ++i) {
            hsh1[i] = (i > 0 ? hsh1[i - 1] : 0) + base[i] * t1[i];
            hsh2[i] = (i > 0 ? hsh2[i - 1] : 0) + base[i] * t2[i];
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            int start = idx - diff[i];

            if (start < 0 || start + len[i] > t1.size() || hsh1[start + len[i] - 1] - (start > 0 ? hsh1[start - 1] : 0) != hsh[i].first * base[start])
                continue;

            if ((start > 0 ? hsh1[start - 1] : 0) + hsh[i].second * base[start] + hsh1.back() - hsh1[start + s[i].second.size() - 1] == hsh2.back())
                ++cnt;
        }

        cout << cnt << '\n';
    }
    
    cout << flush;
    return 0;
}