#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int t;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '0') {
            a[t] = 0;
            t ++;
        }else if (s[i] == '1') {
            a[t] = 1;
            t ++;
        }else if (s[i] == '2') {
            a[t] = 2;
            t ++;
        }else if (s[i] == '3') {
            a[t] = 3;
            t ++;
        }else if (s[i] == '4') {
            a[t] = 4;
            t ++;
        }else if (s[i] == '5') {
            a[t] = 5;
            t ++;
        }else if (s[i] == '6') {
            a[t] = 6;
            t ++;
        }else if (s[i] == '7') {
            a[t] = 7;
            t ++;
        }else if (s[i] == '8') {
            a[t] = 8;
            t ++;
        }else if (s[i] == '9') {
            a[t] = 9;
            t ++;
        }
    }
    sort(a, a + t, cmp);
    for (int i = 0; i < t; i ++) {
        cout << a[i];
    }
    return 0;
}
