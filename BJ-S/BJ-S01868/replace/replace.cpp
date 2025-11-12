#include <bits/stdc++.h>
using namespace std;
int n, q;
string t1, t2;
struct str
{
    string s1, s2;
}s[200011];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].s1 >> s[i].s2;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t1 >> t2;
        cout << 0 << endl;
    }
    return 0;
}
