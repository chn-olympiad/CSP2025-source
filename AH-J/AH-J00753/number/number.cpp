#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    vector<char> v;
    int cnt = 0;
    cin >> s;
    for (char c : s) {
        if (c == '0')
            cnt ++;
        if ('1' <= c && c <= '9')
            v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    while (cnt --)
        cout << 0;
    return 0;
}

