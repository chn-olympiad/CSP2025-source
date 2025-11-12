#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 1e+6 + 5;
string s;
void solve(string t) {
    int num[maxn] = {};
    int a = t.size();
    for (int i = 0; i < t.size(); i++) {
        num[i] = (t[i] - '0');
        //cout << num[i] << " ";
    }
    sort(num, num + t.size(), greater<int>());
    for (int i = 0; i < t.size(); i++) {
        cout << num[i];
    }
    return ;
}
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            tmp += s[i];
        }
    }
    solve(tmp);
    return 0;
}
