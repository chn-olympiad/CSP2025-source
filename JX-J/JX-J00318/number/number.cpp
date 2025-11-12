#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a[s[i]-'0']++;
        }
    }
    for(int i = 9; i >= 0; i--) {
        if(a[i] >= 1) {
            for(int j = 1; j <= a[i]; j++) {
                cout << i;
            }
        }
    }
    return 0;
}
