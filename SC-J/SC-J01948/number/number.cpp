#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[15];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> str;
    int s = str.size();
    for (int i = 0; i < s; i++) {
        if(str[i] > '9' || str[i] < '0')continue;
        cnt[str[i] - '0'] ++;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 1; j <= cnt[i]; j++)cout << i;
    }
    return 0;
}