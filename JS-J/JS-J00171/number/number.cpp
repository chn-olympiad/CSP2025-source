#include<bits/stdc++.h>

using namespace std;

int f[10];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int ans = 0;
    int cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        if (x >= 0 && x <= 9) {
            f[x]++;
            cnt++;
        }
    }
    int t = 1;
    for (int i = 0; i < cnt - 1; i++) t *= 10;
    for (int i = 9; i >= 0; i--) {
        while (f[i]) {
            ans += i * t;
            t /= 10;
            cnt--;
            f[i]--;
        }
    }

    cout << ans << endl;
    return 0;
}
