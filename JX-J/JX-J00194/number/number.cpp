#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string a;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a += s[i];
        }
    }
    sort(a.begin(), a.end());
    for(int i = s.length() - 1; i >= 0; i--) {
        cout << a[i];
    }
}
