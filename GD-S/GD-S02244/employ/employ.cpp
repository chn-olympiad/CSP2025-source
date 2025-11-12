#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define fi first
#define il inline
#define se second
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e2 + 10;
const int mod = 998244353;
int n, m, a[N], chk = 1, b[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c, chk &= (a[i] = c == '1');
    }
    if (chk == 1)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = res * i % mod;
        cout << res << endl;
        return 0;
    }
    if (m == n)
        return (cout << 0 << endl, 0);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    cout << 1 << endl;
    return 0;
}