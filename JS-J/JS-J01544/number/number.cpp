#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int cnt[N];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) cnt[s[i]] += 1;
    for (char c = '9'; c >= '0'; --c)
        for (int i = 1; i <= cnt[c]; ++i) cout << c;

    return 0;
}
