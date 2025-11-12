#include<bits/stdc++.h>
using namespace std;

string s; int cnt[10];

signed main(){
    freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> s;
    for(char c : s) if('0' <= c && c <= '9') cnt[c - '0']++;
    for(int i = 9; i >= 0; --i) for(int j = 1; j <= cnt[i]; ++j) cout << i;

    return 0;
}