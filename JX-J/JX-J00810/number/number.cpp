//rp++  pts+=100
//by dog_emperor
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];
string s;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s; s = '$' + s;
    int l = s.size(), al = 0;
    for (int i = 1; i <= l; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            a[++al] = s[i] - '0';
    }
    sort(a + 1, a + al + 1);
    for (int i = al; i >= 1; --i)
        cout << a[i];
    cout << endl;
    return 0;
}
