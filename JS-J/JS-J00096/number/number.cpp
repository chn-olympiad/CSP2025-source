#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    long long len = s.size();
    vector<char> s1;
    for (long long i = 0; i < len; ++ i) {
        if (s[i] >= '0' && s[i] <= '9') {
            s1.push_back(s[i]);
        }
    }
    sort(s1.begin(), s1.end(), cmp);
    len = s1.size();
    for (long long i = 0; i < len; ++ i) {
        cout << s1[i];
    }
    return 0;
}
