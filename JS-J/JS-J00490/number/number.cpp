#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string s;
int a[10];
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if ('0' <= c && c <= '9') {
            a[c - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 1; j <= a[i]; j++) cout << i;
    }
    cout << endl;
    return 0;
}
