// 8 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int MOD = 998244353;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> c(n);

    for (auto& x : c)
        cin >> x;

    int ans = 0;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    do {
        int success = 0, fail = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' || fail >= c[order[i]])
                ++fail;
            else
                ++success;
        }

        if (success >= m)
            ans = (ans + 1) % MOD;
    } while (next_permutation(order.begin(), order.end()));
    
    cout << ans << endl;
    return 0;
}