# include <bits/stdc++.h>
using namespace std;
map <char , int> m;
string s;
bool f;
int main () {
    freopen ("number.in" , "r" , stdin);
    freopen ("number.out" , "w" , stdout);
    cin >> s;
    for (int i = 0;i < int (s.size ());i ++) {
        if (s[i] >= '0' && s[i] <= '9') {
            m[s[i]] ++;
        }
    }
    for (int i = 9;i >= 0;i --) {
        if (i != 0) {
            for (int j = 1;j <= m[char (i + '0')];j ++) {
                f = true;
                cout << i;
            }
        }
        else if (f) {
            for (int j = 1;j <= m['0'];j ++) {
                cout << 0;
            }
        }
        else cout << 0;
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}
