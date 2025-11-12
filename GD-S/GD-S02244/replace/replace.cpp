#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define il inline
#define se second
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n, q;
map<int, vector<pii>> mp;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        cin >> a >> b;
        int x = a.find('b'), y = b.find('b');
        mp[x - y].pb({x, a.size() - x});
    }
    for (int i = 1; i <= q; i++)
    {
        string a, b;
        cin >> a >> b;
        int x = a.find('b'), y = b.find('b');
        int ans = 0;
        for (auto t : mp[x - y])
            ans += (t.fi <= x && t.se <= a.size() - x);
        cout << ans << endl;
    }
    return 0;
}