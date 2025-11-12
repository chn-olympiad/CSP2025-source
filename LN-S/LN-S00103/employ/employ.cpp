#include <bits/stdc++.h>
using namespace std;
int c[100008];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long sum = 0;
    for(int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    int minn = 1425234242;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        if(c[i]!=0)
        minn = min(minn, c[i]);
    }
cout << minn * sum;

return 0;}
