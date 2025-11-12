#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn = 1e6 + 10;
int num[maxn];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.length();
    int ii = 0;
    for(int i = 0; i < len; ++i) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            num[ii] = s[i] - '0';
            ii++;
        }
    }
    sort(num, num+ii);
    for(int i = ii - 1; i >= 0; --i) cout << num[i];

    return 0;
}