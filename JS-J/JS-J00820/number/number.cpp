#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 30;
string s;
int tong[N];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;

    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            tong[s[i] - '0'] ++;
        }
    }
    for(int i = 9; i >= 0; i--) {
        while(tong[i]) {
            cout << i;
            tong[i]--;
        }
    }

    cout << "\n";
    return 0;
}
