#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0;i < (int)s.length();i++)
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9) a[s[i] - '0']++;
    for (int i = 9;i >= 0;i--)
        for (int j = a[i];j > 0;j--) cout << i;
    return 0;
}
