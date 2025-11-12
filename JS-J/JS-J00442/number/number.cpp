#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
string s;
int num[maxn], cnt;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    getline(cin, s);
    int len = s.size();
    for(int i = 0; i < len; i++) {
        if(isdigit(s[i]))
            num[++cnt] = s[i] - '0';
    }
    sort(num + 1, num + cnt + 1);
    for(int i = cnt; i >= 1; i--)printf("%d", num[i]);
    return 0;
}