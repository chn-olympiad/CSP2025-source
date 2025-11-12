#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10;
int cnt[N];

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    for (const char& i : s)
        if (isdigit(i))
            cnt[i - '0']++;

    for (int i = 9; i >= 0; i--) cout << string(cnt[i], i + '0');

    return 0;
}
