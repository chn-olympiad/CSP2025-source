#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    int s[1000010], v = -1;
    string a;
    cin >> a;
    for (int i = 0;i < a.size();i++)
        if (int(a[i]) >= 48 && int(a[i]) <= 57) {
            v++;
            s[v] = int (a[i]) - 48;
        }
    sort(s, s + v + 1);
    for (int i = v;i >= 0;i--)
        cout << s[i];
    return 0;
}
