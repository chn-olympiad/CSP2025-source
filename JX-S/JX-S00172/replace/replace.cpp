#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[505];
string s11,s12,s21,s22;
string map [200010];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >>q;
    for (int i = 1; i <= n; i ++) {
        cin >> s11 >> s12;
        map([s11]) = s12;
    }
    while (q--) {
        cin >> s21 >> s22;
        cout << "0";
    }
}
