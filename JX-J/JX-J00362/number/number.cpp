#include<bits/stdc++.h>
using namespace std;
int num[15];
string s;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l; i++) {
        int k = s[i] - '0';
        num[k]++;
    }
    for(int i = 9; i >= 0; i--) {
        while(num[i] > 0) {
            cout << i;
            num[i]--;
        }
    }
    return 0;
}
