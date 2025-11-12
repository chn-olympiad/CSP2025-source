#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
string s;
int tmp[N];
int cmp;



signed main () {
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> s;
    for (int i = 0; i < s.size (); i++){
       if ('0' <= s[i] && s[i] <= '9') {
            tmp[s[i] - '0'] ++;
       }
    }

    for (int i = 9 ; i >= 0; i--) {
            for (int j = 1; j <= tmp[i]; j++) cout << i;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
