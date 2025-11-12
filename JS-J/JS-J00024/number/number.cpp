#include <bits/stdc++.h>
using namespace std;

int ton[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(auto i : s) {
        if(i >= '0' && i <= '9') ton[i - '0']++;
    }
    for(int i = 9; i >= 0; i--) {
        while(ton[i]--) cout << i;
    }
    return 0;
}
