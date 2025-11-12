#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int buc[N];
int main () {
    freopen ("r", "number.in", stdin);
    freopen ("w", "number.out", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int x = s[i] - '0';
            buc[x]++;
        }
    }
    int fl = 0;
    for (int i = 9; i >= 0; i--) {
        if (i == 0 && fl == 0) {
            cout << 0 << endl;
        }
        else {
            if (buc[i] > 0) {
                if (i != 0) fl = 1;
                for (int j = 0; j < buc[i]; j++) cout << i;
            }
        }
    }
    return 0;
}