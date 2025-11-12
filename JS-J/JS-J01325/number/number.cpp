#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6;

int n[N + 5];
int cnt;

string s;

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt++;
            n[cnt] = s[i] - '0';
        }
    }
    sort(n + 1, n + 1 + cnt);
    for (int i = cnt; i >= 1; i--) {
        cout << n[i];
    }
    return 0;
}
