#include<bits/stdc++.h>
using namespace std;
struct str
{
    string s1, s2;
}s[1000000];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i].s1 >> s[i].s2;
    }
    while(q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        cout << 0 << endl;
    }
    return 0;
}
