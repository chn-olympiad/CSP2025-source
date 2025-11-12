#include <bits/stdc++.h>
#define lx long long
using namespace std;
string s;
lx n , cnt = 0;
int main () {
    freopen ("number.in" , "r" , stdin);
    freopen ("number.out" , "w" , stdout);
    cin >> s;
    n = s.size();
    for (lx i = 0 ; i < n ; i ++) {
         if (s[i] == '9') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
        if (s[i] == '8') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
         if (s[i] == '7') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
        if (s[i] == '6') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
         if (s[i] == '5') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
        if (s[i] == '4') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
         if (s[i] == '3') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
        if (s[i] == '2') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
         if (s[i] == '1') cout << s[i];
    }
    for (lx i = 0 ; i < n ; i ++) {
        if (s[i] == '0') cout << s[i];
    }
    return 0;
}
