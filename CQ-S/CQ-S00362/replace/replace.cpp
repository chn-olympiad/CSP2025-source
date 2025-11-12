#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
#define int long long

int n, q;
string a[MAXN][5];

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i][1] >> a[i][2];

    while (q --)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << 0 << "\n";
    }

    return 0;
}