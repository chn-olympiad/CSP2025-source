#include <bits/stdc++.h>
using namespace std;
string s;
int t[78];
bool ok;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            t[s[i] - '0'] ++;
        }
    }
    for(int i=9; i>=1; i--) {
        while(t[i] --) {
            cout << i;
            ok = true;
        }
    }
    if(!ok) {
        cout << 0;
    } else {
        while(t[0] --) {
            cout << 0;
        }
    }
    return 0;
}
