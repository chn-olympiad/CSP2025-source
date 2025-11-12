#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;

int cnt[15];

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt[s[i] - '0']++;
        }
    }

    for (int i = 9; i >= 0; i--) {
        while (cnt[i]) {
            putchar(i + '0');
            cnt[i]--;
        }
    }

    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}