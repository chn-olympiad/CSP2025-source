#include<bits/stdc++.h>

using namespace std;

string s;
char a[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0' || s[i] ==  '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
            a[i] = s[i];
    }
    sort(a, a + s.size());
    for(int i = s.size(); i > 1; i--)
        cout << a[i];
    cout << '\n';
    return 0;
}
