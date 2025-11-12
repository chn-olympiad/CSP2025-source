#include <bits/stdc++.h>
using namespace std;
string s;
long long l;
int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    l = (long long) s.size();
    string t = "";
    for (long long i = 0; i < l; i++)
        if (s[i] >= '0' && s[i] <= '9')
            t += s[i];
    sort (t.begin(), t.end());
    long long x = (long long)t.size();
    for (long long i = x - 1; i >= 0; i--)
        cout << t[i];
    cout << '\n';
    return 0;
}
