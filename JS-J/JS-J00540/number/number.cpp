#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int l = s.size(), num[10];
    memset(num, 0, sizeof(num));
    for(int i = 0; i < l; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            num[s[i] - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--) {
        if(num[i] != 0) {
            for(int j = 1; j <= num[i]; j++) {
                cout << i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
