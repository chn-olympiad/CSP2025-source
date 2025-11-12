#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int a[15];
    string s;
    cin >> s;

    for (int i = 0; i <= 9; ++i) a[i] = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (int(s[i]) >= 48 && int(s[i]) <= 57) a[int(s[i]) - 48]++;
    }

    for (int i = 9; i >= 0; --i) {
        while(a[i]) {
            cout << i;
            a[i]--;
        }
    }

    return 0;
}
