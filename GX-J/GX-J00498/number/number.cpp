#include <bits/stdc++.h>
using namespace std;

int a[1000005],mn=INT_MIN,j=0;

int main () {
    freopen("number.in", "r",stdin);
    freopen("number.out", "w",stdout);
    string s;
    cin >> s;
    for (int i=0;i <= s.size()-1;i++) {
        if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
                a[j]=s[i]-'0';
                j++;
        }
    }
    sort (a,a+j);
    for (int i=j-1;i >= 0;i--) {
        cout << a[i];
    }
    return 0;
}
