#include <bits/stdc++.h>
using namespace std;

string s;
char n[10010];
int pos;
bool cmp(char a, char b) {

    return a > b;
}
int main() {
     freopen("number.in", "r", stdin);
     freopen("number.out", "w", stdout);
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0' || s[i] == '1' ||
           s[i] == '2' || s[i] == '3' ||
           s[i] == '4' || s[i] == '5' ||
           s[i] == '6' || s[i] == '7' ||
           s[i] == '8' || s[i] == '9' ) {
                n[++pos] = s[i];
           }

    }
    sort(n + 1, n + 1 + pos, cmp);

    for(int i = 1; i <= pos; i ++) {
        cout << n[i];

    }

    return 0;
}
